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
        const double c_target = 560.0;
        const double Kp = 0.005;
        const double vitesse_x = 0.05;

        double front_error = 0.0;
        double rear_error = 0.0;

        void rgbcFrontCallback(const std_msgs::msg::UInt16MultiArray::SharedPtr msg)
        {
            if (msg -> data.size() < 4)
            {
                RCLCPP_WARN(this -> get_logger(), "Données RGB avant incorrectes");
                return;
            }

            double c = static_cast<double>(msg -> data[3]);
            front_error = c_target - c;

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

            double vy = Kp * (front_error - rear_error) / 2.0;
            vy = std::clamp(vy, -0.05, 0.05);

            double wz = Kp * (front_error - rear_error);
            wz = std::clamp(wz, -0.05, 0.05);

            cmd_vel.linear.x = vitesse_x;
            cmd_vel.linear.y = vy;
            cmd_vel.angular.z = wz;

            RCLCPP_INFO(this -> get_logger(), "Front error: %.1f, Rear error: %.1f, wz: %.2f", front_error, rear_error, wz);

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
