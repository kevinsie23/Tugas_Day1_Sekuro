#include<chrono>
#include<functional>
#include<memory>
#include<string>
#include<vector>
#include<random>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class OrderanPublisher : public rclcpp::Node
{
public:
    OrderanPublisher() : Node("orderan_node")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("masak_topic", 10);

        pesanan_list_ = {"Nasi Goreng", "Mie Ayam", "Bakso", "Sop", "Soto", "Pizza", "Steak", "Burger", "Sushi", "Ramen", "Pasta", "Kebab"};

        std::random_device rd;
        gen_ = std::mt19937(rd());
        dist_ = std::uniform_int_distribution<>(0, pesanan_list_.size() - 1);

        timer_ = this->create_wall_timer(5000ms, std::bind(&OrderanPublisher::timer_callback, this));
    }

    private:
    void timer_callback()
    {
        auto pesanan = std_msgs::msg::String();
        int random_index = dist_(gen_);
        std::string random_order = pesanan_list_[random_index];
        pesanan.data = random_order;
        
        RCLCPP_INFO(this->get_logger(), "'%s' sedang disiapkan", pesanan.data.c_str());
        publisher_->publish(pesanan);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    
    std::vector<std::string> pesanan_list_;
    std::mt19937 gen_;
    std::uniform_int_distribution<> dist_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<OrderanPublisher>());
  rclcpp::shutdown();
  return 0;
}