#pragma once

#include "Renderer.hpp"
#include "TFT_22_ILI9225.h"

class TftRenderer : public Renderer
{
public:
    TftRenderer();
    ~TftRenderer() = default;
    void flush(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color);

private:
    TFT_22_ILI9225 mTft;

    static constexpr uint8_t TFT_RST {PIN_A4};
    static constexpr uint8_t TFT_RS  {PIN_A3};
    static constexpr uint8_t TFT_CS  {PIN_A5};
    static constexpr uint8_t TFT_SDI {PIN_A2};
    static constexpr uint8_t TFT_CLK {PIN_A1};
    static constexpr uint8_t TFT_LED {PIN_A0};
    static constexpr uint8_t TFT_BRIGHTNESS {200};
};