cmake_minimum_required(VERSION 3.22)
project(dual_build_demo LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (${PC})
    add_compile_definitions(PC_BUILD)
else()
    add_compile_definitions(BOARD_BUILD)
    add_library(ArduinoCore
        STATIC
            ${ARDUINO_ROOT}/cores/arduino/CDC.cpp
            ${ARDUINO_ROOT}/cores/arduino/HardwareSerial.cpp
            ${ARDUINO_ROOT}/cores/arduino/HID.cpp
            ${ARDUINO_ROOT}/cores/arduino/IPAddress.cpp
            ${ARDUINO_ROOT}/cores/arduino/main.cpp
            ${ARDUINO_ROOT}/cores/arduino/new.cpp
            ${ARDUINO_ROOT}/cores/arduino/Print.cpp
            ${ARDUINO_ROOT}/cores/arduino/Stream.cpp
            ${ARDUINO_ROOT}/cores/arduino/Tone.cpp
            ${ARDUINO_ROOT}/cores/arduino/USBCore.cpp
            ${ARDUINO_ROOT}/cores/arduino/WInterrupts.c
            ${ARDUINO_ROOT}/cores/arduino/wiring_analog.c
            ${ARDUINO_ROOT}/cores/arduino/wiring.c
            ${ARDUINO_ROOT}/cores/arduino/wiring_digital.c
            ${ARDUINO_ROOT}/cores/arduino/wiring_pulse.c
            ${ARDUINO_ROOT}/cores/arduino/wiring_shift.c
            ${ARDUINO_ROOT}/cores/arduino/WMath.cpp
            ${ARDUINO_ROOT}/cores/arduino/WString.cpp
    )
    target_include_directories(ArduinoCore PUBLIC ${ARDUINO_ROOT})

endif()

add_subdirectory(external)
add_subdirectory(src)