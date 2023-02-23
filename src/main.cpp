#include "lvgl.h"
#ifdef PC_BUILD
#include "PcRenderer.hpp"
#include <signal.h>
#else
#include <Arduino.h>
#include "TftRenderer.hpp"
#endif

int main()
{
#ifdef PC_BUILD
    signal(SIGINT, [](int){exit(0);});
    PcRenderer renderer;
#else
    init();
    TftRenderer renderer;
#endif

    auto* graphicsBuffer = renderer.buffer();

    lv_obj_t* canvas = lv_canvas_create(lv_scr_act());
    lv_canvas_set_buffer(canvas, graphicsBuffer, WIDTH, HEIGHT, LV_IMG_CF_TRUE_COLOR);
    lv_canvas_fill_bg(canvas, lv_color_make(0x00, 0x00, 0xFF), LV_OPA_50);

    while (1)
    {
        renderer.tick();
    }

    return 0;
}