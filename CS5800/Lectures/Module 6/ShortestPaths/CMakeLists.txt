cmake_minimum_required(VERSION 3.10)
project(ShortestPaths CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ShortestPaths ShortestPaths.cpp)
target_include_directories(ShortestPaths PRIVATE include)
