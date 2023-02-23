add_subdirectory(Renderer)
add_subdirectory(Widgets)

add_executable(DualBuildDemo
    main.cpp
)

target_link_libraries(DualBuildDemo
    PUBLIC
        lvgl::lvgl
        Renderer
        Widgets
        ${ARDUINO_CORE_LIB}
)