#include "PcRenderer.hpp"

PcRenderer::PcRenderer()
{
    SDL_Init(SDL_INIT_VIDEO);
    mWindow = SDL_CreateWindow("PC Build", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    mWindowSurface = SDL_GetWindowSurface(mWindow);
    SDL_FillRect(mWindowSurface, nullptr, SDL_MapRGB(mWindowSurface->format, 0x00, 0x00, 0x00));
    SDL_UpdateWindowSurface(mWindow);
}

void PcRenderer::render()
{
    mRenderSurface = SDL_CreateRGBSurfaceWithFormatFrom(mDisplay->driver->draw_buf->buf2, WIDTH, HEIGHT, sizeof(lv_color_t), sizeof(lv_color_t) * WIDTH, SDL_PIXELFORMAT_BGR565);
    SDL_BlitScaled(mRenderSurface, nullptr, mWindowSurface, nullptr);
    SDL_UpdateWindowSurface(mWindow);
    SDL_FreeSurface(mRenderSurface);
    tick();
}