#pragma once

#include "lvgl.h"

class Triangle
{
public:
    Triangle(lv_obj_t* parent, lv_point_t v1, lv_point_t v2, lv_point_t v3);
    ~Triangle();

    void setColor(lv_color_t color);

    const lv_obj_t* const getLvObj() const noexcept;

private:
    static constexpr uint32_t NUM_POINTS {4};

    lv_obj_t* mLine;
    lv_point_t mLinePoints[NUM_POINTS];
    lv_style_t mStyle;
};