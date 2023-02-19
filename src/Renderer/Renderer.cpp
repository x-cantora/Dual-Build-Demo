#include "Renderer.hpp"

static uint32_t secondaryBuffer[NUM_PIXELS];

static void flush(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color)
{
    for(int32_t y = area->y1; y <= area->y2; y++)
    {
        for(int32_t x = area->x1; x <= area->x2; x++)
        {
            secondaryBuffer[(y * WIDTH) + x] = color->full;
            color++;
        }
    }
    lv_disp_flush_ready(drv);
}

Renderer::Renderer()
{
    lv_init();
    lv_disp_draw_buf_init(&mDisplayBuffer, mLvglBuffer, secondaryBuffer, WIDTH * HEIGHT);
    lv_disp_drv_init(&mDisplayDriver); 
    mDisplayDriver.draw_buf = &mDisplayBuffer;   
    mDisplayDriver.flush_cb = flush;
    mDisplayDriver.hor_res = WIDTH;               
    mDisplayDriver.ver_res = HEIGHT;               

    mDisplay = lv_disp_drv_register(&mDisplayDriver);
}

Renderer::~Renderer()
{
    lv_deinit();
}
