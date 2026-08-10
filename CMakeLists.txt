cmake_minimum_required(VERSION 3.14)
project(sophia_simulation CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(sophia src/main.cpp)
