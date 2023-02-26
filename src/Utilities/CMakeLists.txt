set(ARDUINO_LIBRARY_PATH /home/alec/Arduino/libraries/)

# Spi Library
add_library(Spi ${ARDUINO_TOOLCHAIN_ROOT}/libraries/SPI/src/SPI.cpp)
target_link_libraries(Spi PUBLIC ArduinoCore)
target_include_directories(Spi PUBLIC ${ARDUINO_TOOLCHAIN_ROOT}/libraries/SPI/src/)

# TFT Library
file(GLOB TFT_SOURCES LIST_DIRECTORIES FALSE
    ${ARDUINO_LIBRARY_PATH}/TFT_22_ILI9225/src/*.c
    ${ARDUINO_LIBRARY_PATH}/TFT_22_ILI9225/src/*.cpp
)
add_library(Tft ${TFT_SOURCES})
target_link_libraries(Tft PUBLIC Spi ArduinoCore)
target_include_directories(Spi
    PUBLIC
        ${ARDUINO_LIBRARY_PATH}/TFT_22_ILI9225/src/
        ${ARDUINO_LIBRARY_PATH}/TFT_22_ILI9225/fonts/
        ${ARDUINO_LIBRARY_PATH}/TFT_22_ILI9225/images/
)
