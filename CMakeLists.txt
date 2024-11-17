cmake_minimum_required(VERSION 3.10)
project(Renderer VERSION 0.1)

# set cpp standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CONFIG_PATH ${CMAKE_SOURCE_DIR}/include)
set(OUTPUT_PATH ${CMAKE_BINARY_DIR}/include)

# warnings
add_compile_options(-Wall -Wextra -Wshadow -Wconversion -Wfloat-equal -pedantic -Werror)

# Add Eigen
find_package(Eigen3 3.3 REQUIRED)  # System-wide install

#include dirs
include_directories(build/include)

# config
configure_file(${CONFIG_PATH}/RendererConfig.hpp.in ${OUTPUT_PATH}/RendererConfig.hpp)

# Gather shared library sources
file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(GLOB_RECURSE HEADER_FILES "include/*.hpp")

# Add shared library
add_library(shared ${SRC_FILES} ${HEADER_FILES})
target_include_directories(shared PUBLIC include)
target_link_libraries(shared PUBLIC Eigen3::Eigen)  # Link Eigen

# Add programs as subdirectories
add_subdirectory(apps/parser)
add_subdirectory(apps/transform)

# Add tests
# add_subdirectory(tests)