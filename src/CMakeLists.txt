find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(DualBuildDemo
    main.cpp
)

target_link_libraries(DualBuildDemo
    PUBLIC
        lvgl::lvgl
        ${SDL2_LIBRARIES}
)