set(CMAKE_SYSTEM_HOST_NAME Linux)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(CMAKE_SYSTEM_VERSION ${CMAKE_HOST_SYSTEM_VERSION})

set(AVR_MCU "atmega2560")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

set(CMAKE_C_COMPILER   avr-gcc     CACHE PATH "gcc"     FORCE)
set(CMAKE_CXX_COMPILER avr-g++     CACHE PATH "g++"     FORCE)
set(CMAKE_AR           avr-ar      CACHE PATH "ar"      FORCE)
set(CMAKE_LINKER       avr-ld      CACHE PATH "linker"  FORCE)
set(CMAKE_NM           avr-nm      CACHE PATH "nm"      FORCE)
set(CMAKE_OBJCOPY      avr-objcopy CACHE PATH "objcopy" FORCE)
set(CMAKE_OBJDUMP      avr-objdump CACHE PATH "objdump" FORCE)
set(CMAKE_STRIP        avr-strip   CACHE PATH "strip"   FORCE)
set(CMAKE_RANLIB       avr-ranlib  CACHE PATH "ranlib"  FORCE)
set(AVR_SIZE           avr-size    CACHE PATH "size"    FORCE)

set(CMAKE_C_FLAGS "-mmcu=${AVR_MCU} -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections" CACHE FILEPATH "")
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} CACHE FILEPATH "")
set(CMAKE_ASM_FLAGS ${CMAKE_C_FLAGS} CACHE FILEPATH "")
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${AVR_MCU} -Wl,-Map,${PROJECT_BINARY_DIR}/Dual-Build-Demo.map -Wl,--gc-sections" CACHE FILEPATH "")

add_definitions(-DF_CPU=16000000)
set(ARDUINO_ROOT /usr/share/arduino/hardware/arduino/avr)
include_directories(
  ${ARDUINO_ROOT}/cores/arduino
  ${ARDUINO_ROOT}/variants/standard
)
