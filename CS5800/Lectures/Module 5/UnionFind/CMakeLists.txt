cmake_minimum_required(VERSION 3.10)
project(UnionFind CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(UnionFind src/main.cpp src/UnionFind.cpp)
target_include_directories(UnionFind PRIVATE include)
