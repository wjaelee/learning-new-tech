cmake_minimum_required(VERSION 3.16)
project(learn_opencv_c__)
find_package(OpenCV)

set(CMAKE_CXX_STANDARD 14)

add_executable(learn_opencv_c__ main.cpp)