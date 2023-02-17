cmake_minimum_required(VERSION 3.22)
project(dual_build_demo LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)