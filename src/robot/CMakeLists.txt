cmake_minimum_required(VERSION 3.8)
project(robot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(roverc REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(algo_node src/algo_node.cpp)
add_executable(motor_controller src/motor_controller.cpp)
add_executable(trajectory src/trajectory.cpp)
add_executable(trajectory2 src/trajectory2.cpp)
add_executable(tof_servoing src/tof_servoing.cpp)
add_executable(line_servoing_front src/line_servoing_front.cpp)
add_executable(line_servoing_dual src/line_servoing_dual.cpp)

ament_target_dependencies(algo_node rclcpp geometry_msgs std_msgs roverc)
ament_target_dependencies(motor_controller rclcpp geometry_msgs roverc)
ament_target_dependencies(trajectory rclcpp geometry_msgs roverc)
ament_target_dependencies(trajectory2 rclcpp geometry_msgs roverc)
ament_target_dependencies(tof_servoing rclcpp geometry_msgs std_msgs roverc)
ament_target_dependencies(line_servoing_front rclcpp geometry_msgs std_msgs roverc)
ament_target_dependencies(line_servoing_dual rclcpp geometry_msgs std_msgs roverc)

target_include_directories(algo_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(algo_node PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

install(TARGETS algo_node
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS motor_controller
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS trajectory
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS trajectory2
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS tof_servoing
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS line_servoing_front
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS line_servoing_dual
  DESTINATION lib/${PROJECT_NAME})

ament_package()
