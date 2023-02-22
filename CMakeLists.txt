cmake_minimum_required(VERSION 3.22)
project(dual_build_demo LANGUAGES C CXX ASM)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (${PC})
    add_compile_definitions(PC_BUILD)
else()
    add_compile_definitions(BOARD_BUILD)
     file(GLOB ARDUION_SOURCES LIST_DIRECTORIES FALSE 
        ${ARDUINO_ROOT}/cores/arduino/*.c 
        ${ARDUINO_ROOT}/cores/arduino/*.cpp 
        ${ARDUINO_ROOT}/cores/arduino/*.s 
        ${ARDUINO_ROOT}/cores/arduino/*.S 
     ) 
     list(FILTER ARDUION_SOURCES EXCLUDE REGEX "main.cpp") 
     add_library(ArduinoCore ${ARDUION_SOURCES})
     set(ARDUINO_CORE_LIB ArduinoCore)
endif()

add_subdirectory(external)
add_subdirectory(src)