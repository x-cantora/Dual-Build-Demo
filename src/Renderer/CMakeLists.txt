find_package(SDL2 REQUIRED)

add_library(Renderer
    STATIC
        SdlRenderer.cpp
)

target_include_directories(Renderer
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(Renderer
    PUBLIC
        lvgl::lvgl
        ${SDL2_LIBRARIES}
)