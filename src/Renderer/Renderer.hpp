#pragma once

#include "lvgl.h"

#include <stdint.h>

static const uint32_t WIDTH {320};
static const uint32_t HEIGHT {240};
static const uint32_t NUM_PIXELS {WIDTH * HEIGHT};

template<class T>
static void flushArea(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color)
{
    auto* renderer = static_cast<T*>(drv->user_data);
    renderer->flush(drv, area, color);
    lv_disp_flush_ready(drv);
}

class Renderer
{
public:
    Renderer()
    {
        lv_init();
    }
    ~Renderer() = default;

    virtual void flush(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color) = 0;

    lv_color_t* buffer()
    {
        return mLvglBuffer;
    }

    void tick(uint32_t numTicks = 1)
    {
        lv_tick_inc(numTicks);
        lv_timer_handler();
    }

protected:
    lv_color_t mLvglBuffer[NUM_PIXELS];
    lv_disp_drv_t mDisplayDriver;
    lv_disp_draw_buf_t mDisplayBuffer;
    lv_disp_t* mDisplay = nullptr;
};