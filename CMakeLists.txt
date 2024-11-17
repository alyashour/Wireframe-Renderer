# min version
cmake_minimum_required(VERSION 3.10)

# define project
project(Renderer VERSION 0.1)

# set cpp standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set paths for config and output
set(CONFIG_PATH ${CMAKE_SOURCE_DIR}/include)
set(OUTPUT_PATH ${CMAKE_BINARY_DIR}/include)
set(EXECUTABLE_NAME renderer)

# find packages
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

# include
include_directories(build/include ${EIGEN_INCLUDE_DIR})

# config
configure_file(${CONFIG_PATH}/RendererConfig.hpp.in ${OUTPUT_PATH}/RendererConfig.hpp)

# add executable
add_executable(${EXECUTABLE_NAME} src/main.cpp src/ObjParser.cpp)

# target dirs
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${PROJECT_BINARY_DIR} include)

# link eigen lib
target_link_libraries(${EXECUTABLE_NAME} Eigen3::Eigen)
