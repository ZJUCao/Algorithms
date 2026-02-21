cmake_minimum_required(VERSION 3.10)
project(ChangeMaking CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ChangeMaking main.cpp)
target_include_directories(ChangeMaking PRIVATE include)
