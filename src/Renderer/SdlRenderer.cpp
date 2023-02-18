#include "SdlRenderer.hpp"

static uint32_t sdlBuffer[NUM_PIXELS];

void flush(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color)
{
    for(int32_t y = area->y1; y <= area->y2; y++)
    {
        for(int32_t x = area->x1; x <= area->x2; x++)
        {
            sdlBuffer[(y * WIDTH) + x] = color->full;
            color++;
        }
    }
    lv_disp_flush_ready(drv);
}

SdlRenderer::SdlRenderer()
{
    lv_init();
    lv_disp_draw_buf_init(&mDisplayBuffer, mLvglBuffer, sdlBuffer, WIDTH * HEIGHT);
    lv_disp_drv_init(&mDisplayDriver); 
    mDisplayDriver.draw_buf = &mDisplayBuffer;   
    mDisplayDriver.flush_cb = flush;
    mDisplayDriver.hor_res = WIDTH;               
    mDisplayDriver.ver_res = HEIGHT;               

    mDisplay = lv_disp_drv_register(&mDisplayDriver);

    SDL_Init(SDL_INIT_VIDEO);
    mWindow = SDL_CreateWindow("PC Build", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    mWindowSurface = SDL_GetWindowSurface(mWindow);
    SDL_FillRect(mWindowSurface, nullptr, SDL_MapRGB(mWindowSurface->format, 0x00, 0x00, 0x00));
    SDL_UpdateWindowSurface(mWindow);
}

void SdlRenderer::render()
{
    auto* surface = SDL_CreateRGBSurfaceFrom(sdlBuffer, WIDTH, HEIGHT, 32, 4 * WIDTH, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    SDL_BlitScaled(surface, nullptr, mWindowSurface, nullptr);
    SDL_UpdateWindowSurface(mWindow);
    SDL_FreeSurface(surface);
    tick();
}