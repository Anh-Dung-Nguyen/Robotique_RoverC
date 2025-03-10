#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <math.h>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/u_int16_multi_array.hpp"
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
            "/RoverC/rgbc", 10, std::bind(&line_servoing_front::rgbcCallBack, this, _1));
        
            cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/RoverC/cmd_vel", 10);
    }

  private:
    const double c_target = 500.0;
    const double Kp = 0.002;
    const double vitesse_x = 0.07;

    void rgbcCallBack(const std_msgs::msg::UInt16MultiArray::SharedPtr msg)
    {
      if (msg -> data.size() < 4)
      {
        RCLCPP_WARN(this -> get_logger(), "Données RGB incorrectes");
        return;
      }

      double c = static_cast<double>(msg -> data[3]);

      double error = c_target -c;
      double wz = Kp * error;

      wz = std::clamp(wz, -1.0, 1.0);

      RCLCPP_INFO(this -> get_logger(), "c: %.1f, error: %.1f, wz: %.2f", c, error, wz);

      geometry_msgs::msg::Twist cmd_vel;
      cmd_vel.linear.x = vitesse_x;
      cmd_vel.angular.z = wz;

      cmd_vel_pub_ -> publish(cmd_vel);
    }

    rclcpp::Subscription<std_msgs::msg::UInt16MultiArray>::SharedPtr rgbc_sub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<line_servoing_front>());
  rclcpp::shutdown();
  return 0;
}
