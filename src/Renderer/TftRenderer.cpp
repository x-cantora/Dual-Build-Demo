#include "TftRenderer.hpp"

TftRenderer::TftRenderer()
    : mTft(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED, TFT_BRIGHTNESS)
{
    mTft.begin();

    lv_disp_draw_buf_init(&mDisplayBuffer, mLvglBuffer, nullptr, WIDTH * HEIGHT);
    lv_disp_drv_init(&mDisplayDriver); 
    mDisplayDriver.draw_buf = &mDisplayBuffer;   
    mDisplayDriver.hor_res = WIDTH;               
    mDisplayDriver.ver_res = HEIGHT;
    mDisplayDriver.flush_cb = flushArea<TftRenderer>;
    mDisplayDriver.user_data = this;
    mDisplay = lv_disp_drv_register(&mDisplayDriver);
}

void TftRenderer::flush(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color)
{
    uint32_t w = area->x2 - area->x1 + 1;
    uint32_t h = area->y2 - area->y1 + 1;
    for (int32_t y = area->y1; y <= area->y2; y++)
    {
        for(int32_t x = area->x1; x <= area->x2; x++)
        {
            mTft.drawPixel(x, y, color->full);
            color++;
        }
    }
}