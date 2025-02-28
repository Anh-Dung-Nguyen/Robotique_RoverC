#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "roverc/msg/wheel_speed.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class Trajectory2 : public rclcpp::Node
{
    public:
        Trajectory2()
        : Node("trajectory2")
        {
            timer_ = this->create_wall_timer(500ms, std::bind(&Trajectory2::timer_callback, this));
            wheels_pub_ = this->create_publisher<roverc::msg::WheelSpeed>("RoverC/wheels", 1);
            this->declare_parameter<int>("state", 0);
            this->get_parameter("state", state_);
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
                    timer_ = this->create_wall_timer(1s, std::bind(&Trajectory2::timer_callback, this));
                    break;

                case 1:
                    RCLCPP_INFO(this->get_logger(), "Tourner à droite");
                    tourner_a_droite();
                    state_ = 2;
                    timer_->cancel();
                    timer_ = this->create_wall_timer(2s, std::bind(&Trajectory2::timer_callback, this));
                    break;

                case 2:
                    RCLCPP_INFO(this->get_logger(), "Tourner à gauche");
                    tourner_a_gauche();
                    state_ = 3;
                    timer_->cancel();
                    timer_ = this->create_wall_timer(2s, std::bind(&Trajectory2::timer_callback, this));
                    break;
                
                case 3:
                    RCLCPP_INFO(this->get_logger(), "Reculer");
                    reculer();
                    state_ = 0;
                    timer_->cancel();
                    timer_ = this->create_wall_timer(1s, std::bind(&Trajectory2::timer_callback, this));
                    break;
            }
        }

        void avancer()
        {
            roverc::msg::WheelSpeed wheels;
            wheels.front_right = 50;
            wheels.front_left  = 50;
            wheels.rear_right  = 50;
            wheels.rear_left   = 50;
            wheels_pub_->publish(wheels);
        }

        void reculer()
        {
            roverc::msg::WheelSpeed wheels;
            wheels.front_right = -50;
            wheels.front_left  = -50;
            wheels.rear_right  = -50;
            wheels.rear_left   = -50;
            wheels_pub_->publish(wheels);
        }

        void tourner_a_droite()
        {
            roverc::msg::WheelSpeed wheels;
            wheels.front_right = 50;
            wheels.front_left  = -50;
            wheels.rear_right  = 50;
            wheels.rear_left   = -50;
            wheels_pub_->publish(wheels);
        }

        void tourner_a_gauche()
        {
            roverc::msg::WheelSpeed wheels;
            wheels.front_right = -50;
            wheels.front_left  = 50;
            wheels.rear_right  = -50;
            wheels.rear_left   = 50;
            wheels_pub_->publish(wheels);
        }

        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<roverc::msg::WheelSpeed>::SharedPtr wheels_pub_;
        int state_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Trajectory2>());
  rclcpp::shutdown();
  return 0;
}
