#include "TftRenderer.hpp"

void tftFlush(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color)
{
    auto* renderer = static_cast<TftRenderer*>(drv->user_data);
    renderer->flush(drv, area, color);
}

TftRenderer::TftRenderer()
    // : mTft(/*cs, rs, rst*/)
{
    lv_disp_draw_buf_init(&mDisplayBuffer, mLvglBuffer, nullptr, WIDTH * HEIGHT);
    lv_disp_drv_init(&mDisplayDriver); 
    mDisplayDriver.draw_buf = &mDisplayBuffer;   
    mDisplayDriver.hor_res = WIDTH;               
    mDisplayDriver.ver_res = HEIGHT;
    mDisplayDriver.flush_cb = tftFlush;
    mDisplayDriver.user_data = this;
    mDisplay = lv_disp_drv_register(&mDisplayDriver);
}

void TftRenderer::flush(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color)
{
    uint32_t w = area->x2 - area->x1 + 1;
    uint32_t h = area->y2 - area->y1 + 1;

    // mTft.startWrite();
    // mTft.setAddrWindow(area->x1, area->y1, w, h);
    // mTft.pushColors(&color->full, w * h, true);
    // mTft.endWrite();

    lv_disp_flush_ready(drv);
}