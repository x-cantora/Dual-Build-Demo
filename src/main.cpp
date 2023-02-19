#include "gears.h"
#include "lvgl.h"
#include "SdlRenderer.hpp"
#include "Triangle.hpp"
#include "zbuffer.h"

#include <signal.h>

int main()
{
#ifdef PC_BUILD
    signal(SIGINT, [](int){exit(0);});
#endif

    SdlRenderer renderer;
    auto* sdlBuffer = renderer.display()->driver->draw_buf->buf2;

    lv_obj_t* canvas = lv_canvas_create(lv_scr_act());
    lv_canvas_set_buffer(canvas, sdlBuffer, WIDTH, HEIGHT, LV_IMG_CF_TRUE_COLOR);
    gears_init(WIDTH, HEIGHT, ZB_MODE_RGBA, sdlBuffer);

    while (1) {
        gears_update();
        renderer.render();
        usleep(1000);
    }

    return 0;
}