cmake_minimum_required(VERSION 3.0.0)
project(timing_demo VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(timing_demo main.cpp timer.cpp)
