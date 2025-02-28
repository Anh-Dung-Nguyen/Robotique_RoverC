#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "roverc/msg/wheel_speed.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class MotorController : public rclcpp::Node
{
  public:
    MotorController(): Node("motor_controller")
    {
        RCLCPP_INFO(this->get_logger(), "MotorController node started.");
        cmd_vel_sub_ = this->create_subscription<geometry_msgs::msg::Twist>(
            "/RoverC/cmd_vel", 10, std::bind(&MotorController::cmdVelCallback, this, _1));
        wheels_pub_ = this->create_publisher<roverc::msg::WheelSpeed>("/RoverC/wheels", 10);
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/RoverC/cmd_vel", 10);
    }

  private:
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
    {   
        RCLCPP_INFO(this->get_logger(), "cmdVelCallback triggered.");
        RCLCPP_INFO(this->get_logger(), "Received cmd_vel: vx=%.2f, vy=%.2f, wz=%.2f", msg->linear.x, msg->linear.y, msg->angular.z);
        
        double G = 0.2254;
        double r = 0.017; // par exemple
        double lx = 0.018;
        double ly = 0.015;

        double vx = msg->linear.x;
        double vy = msg->linear.y;
        double wz = msg->angular.z;

        double w1 = (vx - vy - (lx + ly) * wz) / (G * r);
        double w2 = (vx + vy + (lx + ly) * wz) / (G * r);
        double w3 = (vx - vy + (lx + ly) * wz) / (G * r);
        double w4 = (vx + vy - (lx + ly) * wz) / (G * r);

        w1 = std::clamp(w1, -100.0, 100.0);
        w2 = std::clamp(w2, -100.0, 100.0);
        w3 = std::clamp(w3, -100.0, 100.0);
        w4 = std::clamp(w4, -100.0, 100.0);

        roverc::msg::WheelSpeed wheels;
        wheels.front_left = static_cast<int>(w1);
        wheels.front_right = static_cast<int>(w2);
        wheels.rear_left = static_cast<int>(w3);
        wheels.rear_right = static_cast<int>(w4);

        wheels_pub_->publish(wheels);

        RCLCPP_INFO(this->get_logger(), "Cmd wheels: FL=%d, FR=%d, RL=%d, RR=%d", wheels.front_left, wheels.front_right, wheels.rear_left, wheels.rear_right);
    }

    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_sub_;
    rclcpp::Publisher<roverc::msg::WheelSpeed>::SharedPtr wheels_pub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MotorController>());
  rclcpp::shutdown();
  return 0;
}


