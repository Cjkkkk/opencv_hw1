cmake_minimum_required(VERSION 3.12)
project(hw1)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

add_executable(hw1 main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(hw1 ${OpenCV_LIBS})