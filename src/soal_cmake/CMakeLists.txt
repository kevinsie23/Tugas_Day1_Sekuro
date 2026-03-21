cmake_minimum_required(VERSION 3.10)
project(robot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(robot_exe
    src/main.cpp
    src/robot.cpp
    src/robotair.cpp
)

target_include_directories(robot_exe PUBLIC include)

set_target_properties(robot_exe PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)