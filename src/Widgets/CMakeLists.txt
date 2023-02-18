
add_library(Widgets
    STATIC
        Triangle.cpp
)

target_include_directories(Widgets
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Widgets
    PUBLIC
        lvgl::lvgl
)