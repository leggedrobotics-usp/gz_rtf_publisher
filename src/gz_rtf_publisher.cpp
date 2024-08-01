#include <iostream>
#include <string>
#include <ignition/msgs.hh>
#include <ignition/transport.hh>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float64.hpp>

class RTFPublisher : public rclcpp::Node {
    public:
        RTFPublisher() : Node("gz_rtf_publisher") {
            // Parameter definition
            this->declare_parameter("topic_name", "/gazebo/real_time_factor");
            // Read parameters
            topic_name_ = this->get_parameter("topic_name").as_string();
            // RTF publisher
            rtf_pub_ = this->create_publisher<std_msgs::msg::Float64>(topic_name_, 1);
            // Subscribe to Gazebo /stats topic
            if(gz_node_.Subscribe("/stats", &RTFPublisher::callback, this)) {
                std::cout << "Subscribed to Gazebo /stats topic." << std::endl;
            }
            else {
                std::cerr << "Failed to subscribe to Gazebo /stats topic!" << std::endl;
            }
        }
    private:
        void callback(const ignition::msgs::WorldStatistics &world_stats_msg) {
            std_msgs::msg::Float64 rtf_msg;
            rtf_msg.data = world_stats_msg.real_time_factor();
            rtf_pub_->publish(rtf_msg);
        }
        std::string topic_name_;
        ignition::transport::Node gz_node_;
        rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr rtf_pub_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<RTFPublisher>());
    rclcpp::shutdown();
    return 0;
}