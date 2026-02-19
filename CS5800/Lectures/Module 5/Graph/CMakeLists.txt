cmake_minimum_required(VERSION 3.10)
project(Graph CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Graph src/main.cpp src/AdjacencyMatrix.cpp src/AdjacencyList.cpp)
target_include_directories(Graph PRIVATE include)
