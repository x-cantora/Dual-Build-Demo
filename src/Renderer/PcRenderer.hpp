#pragma once

#include "Renderer.hpp"

#include <SDL.h>

class PcRenderer : public Renderer
{
public:
    PcRenderer();
    ~PcRenderer() = default;

    void render() override;

private:
    SDL_Window* mWindow = nullptr;
    SDL_Surface* mWindowSurface = nullptr;
    SDL_Surface* mRenderSurface = nullptr;
};
