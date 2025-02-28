#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/u_int16_multi_array.hpp"
#include "roverc/msg/wheel_speed.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class line_servoing_front : public rclcpp::Node
{
  public:
    line_servoing_front(): Node("line_servoing_front")
    {
        RCLCPP_INFO(this->get_logger(), "Line_servoing_front node started.");
        
        rgbc_sub_ = this->create_subscription<std_msgs::msg::UInt16MultiArray>(
            "/RoverC/rgbc", 10, std::bind(&LineServoingFront::rgbcCallback, this, _1));
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/RoverC/cmd_vel", 10);
    }

  private:
    void rgbcCallBack()
    {   
        void rgbcCallback(const std_msgs::msg::UInt16MultiArray::SharedPtr msg)
        {
            geometry_msgs::msg::Twist cmd;
            
            float red = msg->data[0];
            float green = msg->data[1];
            float blue = msg->data[2];

            float erreur = computeError(red, green, blue);

            float Kp = 0.01;

            float maxSpeed = 2;
            float minSpeed = -2;

            cmd.linear.x = 5;
            cmd.angular.z = std::max(std::min(Kp * erreur, maxspeed), minspeed);

            cmd_vel_pub_ -> publish(cmd);
        }

        float computeError(float red, float green, float blue)
        {
            return (red + green) / 2 - blue;
        }

    rclcpp::Subscription<std_msgs::msg::UInt16MultiArray>::SharedPtr rgbc_sub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    }
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<line_servoing_front>());
  rclcpp::shutdown();
  return 0;
}
