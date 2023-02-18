#pragma once

#include "Renderer.hpp"

#include <SDL.h>

class SdlRenderer : public Renderer
{
public:
    SdlRenderer();
    ~SdlRenderer() = default;

    void render() override;

private:
    SDL_Window* mWindow = nullptr;
    SDL_Surface* mWindowSurface = nullptr;
};
