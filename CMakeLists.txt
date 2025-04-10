cmake_minimum_required(VERSION 3.13)
project(gcov_ros2_sample)
set(CMAKE_CXX_STANDARD 17)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

option(COVERAGE_ENABLED "Enable code coverage" FALSE)
message("Code coverage is... ${COVERAGE_ENABLED}")

if(COVERAGE_ENABLED)
  message("Code coverage enabled")
  add_compile_options(--coverage)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --coverage")
endif()

# [Find Dependencies]
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

# [Build]
ament_auto_add_executable(sample_node src/main.cpp)

if(BUILD_TESTING)
  # [Find Test Dependencies]
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  set(ament_cmake_uncrustify_FOUND TRUE)
  find_package(ament_cmake_clang_format REQUIRED)
  ament_lint_auto_find_test_dependencies()

  # [Unit Tests]
  find_package(ament_cmake_gtest REQUIRED)
  ament_auto_add_gtest(test_sample_node test/test_sample_node.cpp)
endif()

# [Install Package]
ament_auto_package()
