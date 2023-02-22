#pragma once

#include "Renderer.hpp"

#include <SDL.h>

class PcRenderer : public Renderer
{
public:
    PcRenderer();
    ~PcRenderer() = default;

    void flush(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color) override final;

private:
    lv_color_t mSdlBuffer[NUM_PIXELS];
    SDL_Window* mWindow = nullptr;
    SDL_Surface* mWindowSurface = nullptr;
    SDL_Surface* mRenderSurface = nullptr;
};
