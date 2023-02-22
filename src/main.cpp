#include "lvgl.h"
#ifdef PC_BUILD
#include "PcRenderer.hpp"
#else
#include "TftRenderer.hpp"
#endif

#include <signal.h>

int main()
{
#ifdef PC_BUILD
    signal(SIGINT, [](int){exit(0);});
#endif

#ifdef PC_BUILD
    PcRenderer renderer;
#else
    TftRenderer renderer;
#endif

    auto* sdlBuffer = renderer.display()->driver->draw_buf->buf2;

    lv_obj_t* canvas = lv_canvas_create(lv_scr_act());
    lv_canvas_set_buffer(canvas, sdlBuffer, WIDTH, HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_canvas_fill_bg(canvas, lv_color_make(0xFF, 0x00, 0x00), LV_OPA_50);

    while (1)
    {
        renderer.render();
    }

    return 0;
}