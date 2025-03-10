#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/u_int16_multi_array.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class line_servoing_dual : public rclcpp::Node
{
    public:
        line_servoing_dual() : Node("line_servoing_dual")
        {
            RCLCPP_INFO(this->get_logger(), "Line Servoing Dual node started.");
            
            front_sensor_sub_ = this->create_subscription<std_msgs::msg::UInt16MultiArray>(
                "/RoverC/rgbc", 10, std::bind(&line_servoing_dual::rgbcFrontCallback, this, _1));
            
            rear_sensor_sub_ = this->create_subscription<std_msgs::msg::UInt16MultiArray>(
                "/RoverC/rgbc2", 10, std::bind(&line_servoing_dual::rgbcRearCallback, this, _1));
        
            cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/RoverC/cmd_vel", 10);
        }

    private:
        const double c_target = 550.0;
        const double Kp = 0.002;
        const double vitesse_x = 0.07;
        const double seuil_perte_ligne = 680.0;
        const double vitesse_rotation = 10.0;

        double front_error = 0.0;
        double rear_error = 0.0;
        bool virage_detecte = false;

        void rgbcFrontCallback(const std_msgs::msg::UInt16MultiArray::SharedPtr msg)
        {
            if (msg -> data.size() < 4)
            {
                RCLCPP_WARN(this -> get_logger(), "Données RGB avant incorrectes");
                return;
            }

            double c = static_cast<double>(msg -> data[3]);
            front_error = c_target - c;

            if (c > seuil_perte_ligne)
            {
                virage_detecte = true;
            }

            publishCmdVel();
        }

        void rgbcRearCallback(const std_msgs::msg::UInt16MultiArray::SharedPtr msg)
        {
            if (msg -> data.size() < 4)
            {
                RCLCPP_WARN(this -> get_logger(), "Données RGB arrière incorrectes");
                return;
            }

            double c = static_cast<double>(msg -> data[3]);
            rear_error = c_target - c;

            publishCmdVel();
        }

        void publishCmdVel()
        {
            geometry_msgs::msg::Twist cmd_vel;

            if (virage_detecte)
            {
                cmd_vel.linear.x = vitesse_x / 10;
                cmd_vel.angular.z = vitesse_rotation;
                RCLCPP_INFO(this->get_logger(), "Virage détecté: rotation en cours.");

                rclcpp::sleep_for(500ms);
                virage_detecte = false;
            }
            else
            {
                double wz = Kp * (front_error - rear_error);
                wz = std::clamp(wz, -1.0, 1.0);

                cmd_vel.linear.x = vitesse_x;
                cmd_vel.angular.z = wz;

                RCLCPP_INFO(this -> get_logger(), "Front error: %.1f, Rear error: %.1f, wz: %.2f", front_error, rear_error, wz);
            }

            cmd_vel_pub_ -> publish(cmd_vel);
        }

        rclcpp::Subscription<std_msgs::msg::UInt16MultiArray>::SharedPtr front_sensor_sub_;
        rclcpp::Subscription<std_msgs::msg::UInt16MultiArray>::SharedPtr rear_sensor_sub_;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<line_servoing_dual>());
    rclcpp::shutdown();
    return 0;
}
