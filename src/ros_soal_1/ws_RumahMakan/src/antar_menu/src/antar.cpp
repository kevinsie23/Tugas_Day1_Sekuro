#include<memory>
#include<string>
#include<chrono>
#include<thread>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class AntarSubscriber : public rclcpp::Node
{
public:
    AntarSubscriber() : Node("antar_node")
    {
        // Create a subscription to "topic_name"
        // When a message arrives, 'topic_callback' is executed
        subscription_ = this->create_subscription<std_msgs::msg::String>(
        "masak_topic", 10, std::bind(&AntarSubscriber::topic_callback, this, _1));
    }

    private:
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
        std::string makanan = msg->data;
        RCLCPP_INFO(this->get_logger(), "Diterima: '%s'", makanan.c_str());
        RCLCPP_INFO(this->get_logger(), "Makanan sedang diproses... Harap menunggu!");

        std::this_thread::sleep_for(std::chrono::seconds(7));

        RCLCPP_INFO(this->get_logger(), "Selesai! '%s' siap disajikan.", makanan.c_str());
        RCLCPP_INFO(this->get_logger(), "-----------------------------");

        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<AntarSubscriber>());
  rclcpp::shutdown();
  return 0;
}