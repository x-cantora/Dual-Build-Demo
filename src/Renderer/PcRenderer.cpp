#include "PcRenderer.hpp"

PcRenderer::PcRenderer()
{
    lv_disp_draw_buf_init(&mDisplayBuffer, mLvglBuffer, nullptr, WIDTH * HEIGHT);
    lv_disp_drv_init(&mDisplayDriver); 
    mDisplayDriver.draw_buf = &mDisplayBuffer;   
    mDisplayDriver.hor_res = WIDTH;               
    mDisplayDriver.ver_res = HEIGHT;   
    mDisplayDriver.flush_cb = flushArea<PcRenderer>;
    mDisplayDriver.user_data = this;
    mDisplay = lv_disp_drv_register(&mDisplayDriver);

    SDL_Init(SDL_INIT_VIDEO);
    mWindow = SDL_CreateWindow("PC Build", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    mWindowSurface = SDL_GetWindowSurface(mWindow);
    SDL_FillRect(mWindowSurface, nullptr, SDL_MapRGB(mWindowSurface->format, 0x00, 0x00, 0x00));
    SDL_UpdateWindowSurface(mWindow);
}

void PcRenderer::flush(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color)
{
    for (int32_t y = area->y1; y <= area->y2; y++)
    {
        for(int32_t x = area->x1; x <= area->x2; x++)
        {
            mLvglBuffer[(y * WIDTH) + x].full = color->full;
            color++;
        }
    }

    mRenderSurface = SDL_CreateRGBSurfaceWithFormatFrom(mLvglBuffer, WIDTH, HEIGHT, sizeof(lv_color_t), sizeof(lv_color_t) * WIDTH, SDL_PIXELFORMAT_BGR565);
    SDL_BlitScaled(mRenderSurface, nullptr, mWindowSurface, nullptr);
    SDL_UpdateWindowSurface(mWindow);
    SDL_FreeSurface(mRenderSurface);
}