# create proj
cmake_minimum_required(VERSION 3.10)
project(Renderer VERSION 0.1)

# warnings
add_compile_options(-Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -pedantic -Werror)


# set vars
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CONFIG_PATH ${CMAKE_SOURCE_DIR}/include)
set(OUTPUT_PATH ${CMAKE_BINARY_DIR}/include)

# config
configure_file(${CONFIG_PATH}/RendererConfig.hpp.in ${OUTPUT_PATH}/RendererConfig.hpp)

# dirs
include_directories(include)

# executable
add_executable(Renderer src/main.cpp src/ObjParser.cpp)

# target dirs
target_include_directories(Renderer PUBLIC "${PROJECT_BINARY_DIR}")
