#pragma once

#include <rclcpp/rclcpp.hpp>

class SampleNode : public rclcpp::Node
{
public:
  SampleNode() : Node("sample_node") {}
  ~SampleNode() = default;

  int addTwoInts(int a, int b) { return a + b; }

  int addTwoIntsIf(bool condition, int a, int b)
  {
    if (condition) {
      return a + b;
    } else {
      return 0;
    }
  }
};
