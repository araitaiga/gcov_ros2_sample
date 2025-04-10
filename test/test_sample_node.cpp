#include <gtest/gtest.h>

#include <memory>
#include <rclcpp/rclcpp.hpp>

#include "gcov_ros2_sample/sample_node.hpp"

class TestSampleNode : public ::testing::Test
{
protected:
  void SetUp() override
  {
    rclcpp::init(0, nullptr);
    node = std::make_shared<SampleNode>();
  }

  void TearDown() override
  {
    node.reset();
    rclcpp::shutdown();
  }

  std::shared_ptr<SampleNode> node;
};

TEST_F(TestSampleNode, TestAddInts)
{
  EXPECT_EQ(node->addTwoInts(3, 4), 7);
  EXPECT_EQ(node->addTwoInts(10, 20), 30);
  EXPECT_EQ(node->addTwoInts(0, 5), 5);
}

TEST_F(TestSampleNode, TestAddTwoIntsIf)
{
  EXPECT_EQ(node->addTwoIntsIf(true, 3, 4), 7);
  EXPECT_EQ(node->addTwoIntsIf(false, 10, 20), 0);
  EXPECT_EQ(node->addTwoIntsIf(true, 0, 5), 5);
}

// gtestのメイン関数
int main(int argc, char ** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
