#include "lvgl.h"
#include "SdlRenderer.hpp"
#include "Triangle.hpp"

#include <signal.h>

int main()
{
#ifdef PC_BUILD
    signal(SIGINT, [](int){exit(0);});
#endif

    SdlRenderer renderer;

    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_white(), LV_PART_MAIN);
    Triangle triangle(lv_scr_act(), {0,0}, {30,30}, {0,60});
    triangle.setColor(lv_color_black());

    int32_t moveAmount = 1;
    while (1) 
    {
        triangle.move(moveAmount, moveAmount);
        if (triangle.getPoints()[0].x == WIDTH || triangle.getPoints()[0].x == 0)
        {
            moveAmount *= -1;
        }
        usleep(1000);
        renderer.render();
    }

    return 0;
}