add_subdirectory(Renderer)
add_subdirectory(Widgets)
if (NOT ${PC})
    add_subdirectory(Utilities)
endif()

add_executable(DualBuildDemo
    main.cpp
)

target_link_libraries(DualBuildDemo
    PUBLIC
        lvgl::lvgl
        Renderer
        ${ARDUINO_CORE_LIB}
)