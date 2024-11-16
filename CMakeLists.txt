cmake_minimum_required(VERSION 3.10)
project(wireframe-renderer VERSION 1.0)

set(CMAKE_CXX_STANDARD 23)
include_directories(include)
add_executable(render src/main.cpp src/ObjParser.cpp)