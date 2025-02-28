#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "roverc/msg/wheel_speed.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class Trajectory : public rclcpp::Node
{
    public:
        Trajectory() : Node("trajectory")
        {
            state_ = 0;
            cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/RoverC/cmd_vel", 10);
            timer_ = this->create_wall_timer(500ms, std::bind(&Trajectory::timer_callback, this));
            RCLCPP_INFO(this->get_logger(), "Trajectory started");
        }

    private:
        void timer_callback()
        {
            switch (state_)
            {
                case 0:
                    RCLCPP_INFO(this->get_logger(), "Avancer");
                    avancer();
                    state_ = 1;
                    timer_->cancel();
                    timer_ = this->create_wall_timer(1s, std::bind(&Trajectory::timer_callback, this));
                    break;

                case 1:
                    RCLCPP_INFO(this->get_logger(), "Tourner à droite");
                    tourner_a_droite();
                    state_ = 2;
                    timer_->cancel();
                    timer_ = this->create_wall_timer(2s, std::bind(&Trajectory::timer_callback, this));
                    break;

                case 2:
                    RCLCPP_INFO(this->get_logger(), "Tourner à gauche");
                    tourner_a_gauche();
                    state_ = 3;
                    timer_->cancel();
                    timer_ = this->create_wall_timer(2s, std::bind(&Trajectory::timer_callback, this));
                    break;
                
                case 3:
                    RCLCPP_INFO(this->get_logger(), "Reculer");
                    reculer();
                    state_ = 0;
                    timer_->cancel();
                    timer_ = this->create_wall_timer(1s, std::bind(&Trajectory::timer_callback, this));
                    break;
            }
        }

        void avancer()
        {
            geometry_msgs::msg::Twist cmd_vel;
            cmd_vel.linear.x = 5.0;
            cmd_vel_pub_->publish(cmd_vel);
        }

        void reculer()
        {
            geometry_msgs::msg::Twist cmd_vel;
            cmd_vel.linear.x = -5.0;
            cmd_vel_pub_->publish(cmd_vel);
        }

        void tourner_a_droite()
        {
            geometry_msgs::msg::Twist cmd_vel;
            cmd_vel.angular.z = 5.0;
            cmd_vel_pub_->publish(cmd_vel);
        }

        void tourner_a_gauche()
        {
            geometry_msgs::msg::Twist cmd_vel;
            cmd_vel.angular.z = -5.0;
            cmd_vel_pub_->publish(cmd_vel);
        }

        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
        rclcpp::TimerBase::SharedPtr timer_;
        int state_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Trajectory>());
  rclcpp::shutdown();
  return 0;
}