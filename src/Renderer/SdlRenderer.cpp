#include "SdlRenderer.hpp"

SdlRenderer::SdlRenderer()
{
    SDL_Init(SDL_INIT_VIDEO);
    mWindow = SDL_CreateWindow("PC Build", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    mWindowSurface = SDL_GetWindowSurface(mWindow);
    SDL_FillRect(mWindowSurface, nullptr, SDL_MapRGB(mWindowSurface->format, 0x00, 0x00, 0x00));
    SDL_UpdateWindowSurface(mWindow);
}

void SdlRenderer::render()
{
    auto* surface = SDL_CreateRGBSurfaceFrom(mDisplay->driver->draw_buf->buf2, WIDTH, HEIGHT, 32, 4 * WIDTH, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    SDL_BlitScaled(surface, nullptr, mWindowSurface, nullptr);
    SDL_UpdateWindowSurface(mWindow);
    SDL_FreeSurface(surface);
    tick();
}