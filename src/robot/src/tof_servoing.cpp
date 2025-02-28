#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class Tof_servoing : public rclcpp::Node
{
    public:
        Tof_servoing(float kp, float ki, float kd) : Node("tof_servoing"), Kp(kp), Ki(ki), Kd(kd)
        {
            last_error = 0.0;
            diff = 0.0;
            errorsum = 0.0;
            maxspeed = 3.0;   
            minspeed = -3.0;
            maxsum = 0.1;
            minsum = -0.1;

            dist_sub_ = this->create_subscription<std_msgs::msg::Float32>("/RoverC/distance", 10,
                                std::bind(&Tof_servoing::distanceCallback, this, _1));
            cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("RoverC/cmd_vel", 10);
        }
    
    private:
        float last_error;
        float diff;
        float errorsum ;
        float Kp ;
        float Ki ;
        float Kd ;
        float maxspeed;   
        float minspeed;
        float maxsum;
        float minsum;

        void distanceCallback(const std_msgs::msg::Float32::SharedPtr msg)
        {
            geometry_msgs::msg::Twist cmd_vel;
            float distance = msg->data;
            float target_distance = 0.1;
            
            float error = distance - target_distance;
            diff = error - last_error;
            last_error = error;

            if (std::abs(error) < 0.1) { 
                errorsum = 0;
            } else {
                errorsum += error;
                errorsum = std::max(std::min(errorsum, maxsum), minsum);
            }

            float speed = Kp * error + Ki * errorsum + Kd * diff;
            speed = std::max(std::min(speed, maxspeed), minspeed);
            cmd_vel.linear.x = speed;

            RCLCPP_INFO(get_logger(),"Error : %f, Sum : %f, Diff :  %f", error, errorsum, diff);
            cmd_vel_pub_->publish(cmd_vel);

        }

        rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr dist_sub_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;

};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);


    // Configuration intéréssantes : 
    //0.02 0.005 0.02 précis mais un peu lent
    //0.04 0.008 0.02 + rapide mais moins stable
    //0.04 0.008 0.03 + stable et fonctionne relativement bien mais souffre de l'instabilité du robot

    float default_kp = 0.02;
    float default_ki = 0.005;
    float default_kd = 0.02;

    if (argc == 4) {
        default_kp = std::stof(argv[1]);
        default_ki = std::stof(argv[2]);
        default_kd = std::stof(argv[3]);
    } else {
        RCLCPP_WARN(rclcpp::get_logger("tof_servoing"), "Incorrect imput -> default kp/ki/kd");
        RCLCPP_WARN(rclcpp::get_logger("tof_servoing"), "Respect this structure: ros2 run robot tof_servoing [Kp] [Ki] [Kd]");
    }

    rclcpp::spin(std::make_shared<Tof_servoing>(default_kp, default_ki, default_kd));
    rclcpp::shutdown();
    return 0;
}