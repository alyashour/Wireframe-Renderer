# set vars
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CONFIG_PATH ${CMAKE_SOURCE_DIR}/include)
set(OUTPUT_PATH ${CMAKE_BINARY_DIR}/include)
set(DEPENDENCIES_PATH externals)
set(EXECUTABLE_NAME renderer)

# create proj
cmake_minimum_required(VERSION 3.10)
project(Renderer VERSION 0.1)

# warnings
# add_compile_options(-Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -pedantic -Werror)

# config
configure_file(${CONFIG_PATH}/RendererConfig.hpp.in ${OUTPUT_PATH}/RendererConfig.hpp)

# dirs
add_subdirectory(${DEPENDENCIES_PATH}/eigen)
include_directories(include)

# executable
add_executable(${EXECUTABLE_NAME} src/main.cpp src/ObjParser.cpp)

# target dirs
target_include_directories(${EXECUTABLE_NAME} PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(${EXECUTABLE_NAME} eigen)
