cmake_minimum_required(VERSION 3.10)
project(SearchAlgorithms CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(LinearSearch LinearSearch.cpp)
add_executable(ChunkSearch  ChunkSearch.cpp)
add_executable(BinarySearch BinarySearch.cpp)
