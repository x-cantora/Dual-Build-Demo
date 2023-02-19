#pragma once

#include "lvgl.h"

#include <cstdint>

static const uint32_t WIDTH {320};
static const uint32_t HEIGHT {240};
static const uint32_t NUM_PIXELS {WIDTH * HEIGHT};

class Renderer
{
public:
    Renderer();
    ~Renderer();

    virtual void render() = 0;
    lv_disp_t* display()
    {
        return mDisplay;
    }

protected:
    uint32_t mLvglBuffer[NUM_PIXELS];
    lv_disp_drv_t mDisplayDriver;
    lv_disp_draw_buf_t mDisplayBuffer;
    lv_disp_t* mDisplay = nullptr;

    void tick(uint32_t numTicks = 1)
    {
        lv_tick_inc(numTicks);
        lv_timer_handler();
    }
};