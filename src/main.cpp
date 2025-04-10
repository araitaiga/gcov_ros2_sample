#include <iostream>
#include <rclcpp/rclcpp.hpp>

#include "gcov_ros2_sample/sample_node.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SampleNode>();
  std::cout << "Result: " << node->addTwoInts(3, 4) << std::endl;
  rclcpp::shutdown();
  return 0;
}
