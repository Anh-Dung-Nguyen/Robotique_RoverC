#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/u_int16_multi_array.hpp"
#include "std_msgs/msg/float32.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class line_wall_follower : public rclcpp::Node
{
public:
    line_wall_follower() : Node("line_wall_follower"), state(FOLLOW_LINE)
    {
        RCLCPP_INFO(this->get_logger(), "Node started: line_wall_follower");

        front_sensor_sub_ = this->create_subscription<std_msgs::msg::UInt16MultiArray>(
            "/RoverC/rgbc", 10, std::bind(&line_wall_follower::rgbcFrontCallback, this, _1));
        
        rear_sensor_sub_ = this->create_subscription<std_msgs::msg::UInt16MultiArray>(
            "/RoverC/rgbc2", 10, std::bind(&line_wall_follower::rgbcRearCallback, this, _1));
        
        right_dist_sub_ = this->create_subscription<std_msgs::msg::Float32>(
            "/RoverC/distance", 10, std::bind(&line_wall_follower::distanceRightCallback, this, _1));

        left_dist_sub_ = this->create_subscription<std_msgs::msg::Float32>(
            "/RoverC/distance2", 10, std::bind(&line_wall_follower::distanceLeftCallback, this, _1));
        
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/RoverC/cmd_vel", 10);
    }

private:
    enum State { FOLLOW_LINE, FOLLOW_WALL };
    State state;
    
    const double c_target = 560.0;
    const double Kp = 0.005;
    const double vitesse_x = 0.05;
    const float wall_distance_target = 0.06;
    const float lateral_speed = 0.05;
    
    double front_error = 0.0;
    double rear_error = 0.0;
    float right_distance = 0.0;
    float left_distance = 0.0;

    void rgbcFrontCallback(const std_msgs::msg::UInt16MultiArray::SharedPtr msg)
    {
        if (msg->data.size() < 4)
        {
            RCLCPP_WARN(this->get_logger(), "Données RGB avant incorrectes");
            return;
        }
        front_error = c_target - static_cast<double>(msg->data[3]);
        controlRobot();
    }

    void rgbcRearCallback(const std_msgs::msg::UInt16MultiArray::SharedPtr msg)
    {
        if (msg->data.size() < 4)
        {
            RCLCPP_WARN(this->get_logger(), "Données RGB arrière incorrectes");
            return;
        }
        rear_error = c_target - static_cast<double>(msg->data[3]);
        controlRobot();
    }

    void distanceRightCallback(const std_msgs::msg::Float32::SharedPtr msg)
    {
        right_distance = msg->data;
        controlRobot();
    }

    void distanceLeftCallback(const std_msgs::msg::Float32::SharedPtr msg)
    {
        left_distance = msg->data;
        controlRobot();
    }

    void controlRobot()
    {
        geometry_msgs::msg::Twist cmd_vel;
        
        if (state == FOLLOW_LINE)
        {
            if (right_distance < wall_distance_target || left_distance < wall_distance_target)
            {
                state = FOLLOW_WALL;
                RCLCPP_INFO(this->get_logger(), "Mur détecté ! Passage en mode suivi du mur.");
            }
            else
            {
                double vy = Kp * (front_error - rear_error) / 2.0;
                vy = std::clamp(vy, -0.05, 0.05);

                double wz = Kp * (front_error - rear_error);
                wz = std::clamp(wz, -0.05, 0.05);

                cmd_vel.linear.x = vitesse_x;
                cmd_vel.linear.y = vy;
                cmd_vel.angular.z = wz;
            }
        }
        else if (state == FOLLOW_WALL)
        {
            if (front_error < 50.0)
            {
                state = FOLLOW_LINE;
                RCLCPP_INFO(this->get_logger(), "Ligne détectée, retour au suivi de ligne.");
            }
            else
            {
                float e1 = right_distance - wall_distance_target;
                float e2 = left_distance - wall_distance_target;

                float b = wall_distance_target;
                float c = std::sqrt(2 * b * b * (1 + cos(M_PI / 8)));
                float d = std::sqrt(right_distance * right_distance + left_distance * left_distance + 2 * right_distance * left_distance * cos(M_PI / 8));
                float numerator = (right_distance - left_distance) * (right_distance - left_distance) - c * c - d * d;
                float denumerator = 2 * c * d;

                float alpha = 0.0;
                if (denumerator != 0)
                {
                    alpha = std::acos(std::clamp(numerator / denumerator, -1.0f, 1.0f));
                }

                float vx = Kp * (e1 + e2) / 2.0;
                float wz = -Kp * alpha;

                cmd_vel.linear.x = vx;
                cmd_vel.linear.y = lateral_speed;
                cmd_vel.angular.z = wz;
            }
        }

        cmd_vel_pub_->publish(cmd_vel);
    }

    rclcpp::Subscription<std_msgs::msg::UInt16MultiArray>::SharedPtr front_sensor_sub_;
    rclcpp::Subscription<std_msgs::msg::UInt16MultiArray>::SharedPtr rear_sensor_sub_;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr right_dist_sub_;
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr left_dist_sub_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<line_wall_follower>());
    rclcpp::shutdown();
    return 0;
}
