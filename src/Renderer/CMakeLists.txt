if (${PC})
    find_package(SDL2 REQUIRED)
    set(SOURCE Pc)
else()
    set(SOURCE Tft)
    set(ARDUINO_LIBS Tft)
endif()

add_library(Renderer
    STATIC
        ${SOURCE}Renderer.cpp
)

target_include_directories(Renderer
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(Renderer
    PUBLIC
        lvgl::lvgl
        ${ARDUINO_LIBS}
        ${SDL2_LIBRARIES}
)