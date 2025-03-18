#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class Detecte_mur : public rclcpp::Node
{
    public:
        Detecte_mur(float kp, float ki, float kd) : Node("detecte_mur"), Kp(kp), Ki(ki), Kd(kd)
        {
            last_error = 0.0;
            diff = 0.0;
            errorsum = 0.0;
            maxspeed = 3.0;   
            minspeed = -3.0;
            maxsum = 0.1;
            minsum = -0.1;

            dist_sub_left_ = this->create_subscription<std_msgs::msg::Float32>("/RoverC/distance_left", 10,
                                std::bind(&Detecte_mur::distanceCallbackLeft, this, _1));
            
            dist_sub_right_ = this->create_subscription<std_msgs::msg::Float32>("/RoverC/distance_right", 10,
                                std::bind(&Detecte_mur::distanceCallbackRight, this, _1));

            cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("RoverC/cmd_vel", 10);
        }
    
    private:
        float last_error;
        float diff;
        float errorsum;
        float Kp;
        float Ki;
        float Kd;
        float maxspeed;   
        float minspeed;
        float maxsum;
        float minsum;
        float distance_left;
        float distance_right;
        
        void distanceCallbackLeft(const std_msgs::msg::Float32::SharedPtr msg)
        {
            distance_left = msg->data;
            computeAndPublishVelocity();
        }
        
        void distanceCallbackRight(const std_msgs::msg::Float32::SharedPtr msg)
        {
            distance_right = msg->data;
            computeAndPublishVelocity();
        }
        
        void computeAndPublishVelocity()
        {
            if (distance_left == 0.0 || distance_right == 0.0) return; // Attendre les deux capteurs
            
            geometry_msgs::msg::Twist cmd_vel;
            float error = distance_left - distance_right;
            
            if (std::abs(error) < 0.01) { // Si les distances sont égales
                cmd_vel.linear.y = 0.5; // Déplacement latéral
            } else if (distance_right < distance_left) {
                cmd_vel.angular.z = 0.3; // Correction de la position
            }
            
            RCLCPP_INFO(get_logger(), "Distance Left: %f, Distance Right: %f, Error: %f", distance_left, distance_right, error);
            cmd_vel_pub_->publish(cmd_vel);
        }

        rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr dist_sub_left_;
        rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr dist_sub_right_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    float default_kp = 0.02;
    float default_ki = 0.005;
    float default_kd = 0.02;

    if (argc == 4) {
        default_kp = std::stof(argv[1]);
        default_ki = std::stof(argv[2]);
        default_kd = std::stof(argv[3]);
    } else {
        RCLCPP_WARN(rclcpp::get_logger("Detecte_mur"), "Incorrect input -> default kp/ki/kd");
        RCLCPP_WARN(rclcpp::get_logger("Detecte_mur"), "Respect this structure: ros2 run robot detecte_mur [Kp] [Ki] [Kd]");
    }

    rclcpp::spin(std::make_shared<Detecte_mur>(default_kp, default_ki, default_kd));
    rclcpp::shutdown();
    return 0;
}