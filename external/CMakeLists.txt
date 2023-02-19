set(LV_CONF_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lv_conf.h CACHE STRING "" FORCE)
add_subdirectory(lvgl)

add_library(lv_tinygl
    STATIC
        lv_lib_tinygl/src/api.c         
        lv_lib_tinygl/src/arrays.c      
        lv_lib_tinygl/src/clear.c       
        lv_lib_tinygl/src/clip.c        
        lv_lib_tinygl/src/error.c       
        lv_lib_tinygl/src/gears.c       
        lv_lib_tinygl/src/get.c         
        lv_lib_tinygl/src/glu.c         
        lv_lib_tinygl/src/image_util.c  
        lv_lib_tinygl/src/init.c        
        lv_lib_tinygl/src/light.c        
        lv_lib_tinygl/src/list.c         
        lv_lib_tinygl/src/matrix.c       
        lv_lib_tinygl/src/memory.c       
        lv_lib_tinygl/src/misc.c         
        lv_lib_tinygl/src/msghandling.c  
        lv_lib_tinygl/src/objtest.c      
        lv_lib_tinygl/src/oscontext.c    
        lv_lib_tinygl/src/select.c
        lv_lib_tinygl/src/specbuf.c
        lv_lib_tinygl/src/texture.c
        lv_lib_tinygl/src/triangle.c
        lv_lib_tinygl/src/vertex.c
        lv_lib_tinygl/src/zbuffer.c
        lv_lib_tinygl/src/zdither.c
        lv_lib_tinygl/src/zline.c
        lv_lib_tinygl/src/zmath.c
        lv_lib_tinygl/src/ztriangle.c
)

target_link_libraries(lv_tinygl
    PUBLIC
        lvgl::lvgl
)

target_include_directories(lv_tinygl
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/lv_lib_tinygl
        ${CMAKE_CURRENT_LIST_DIR}/lv_lib_tinygl/src
)
