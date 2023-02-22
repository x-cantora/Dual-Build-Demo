#pragma once

#include "Renderer.hpp"
// #include "TFT.h"

class TftRenderer : public Renderer
{
public:
    TftRenderer();
    ~TftRenderer() = default;
    void flush(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color) override final;

private:
    // TFT mTft;
};