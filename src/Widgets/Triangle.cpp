#include "Triangle.hpp"

Triangle::Triangle(lv_obj_t* parent, lv_point_t v1, lv_point_t v2, lv_point_t v3)
    : mLine{lv_line_create(parent)}
    , mLinePoints{v1, v2, v3, v1}
{
    lv_line_set_points(mLine, mLinePoints, NUM_POINTS);
    
    lv_style_init(&mStyle);
    lv_style_set_line_width(&mStyle, 1);
    lv_style_set_line_color(&mStyle, lv_color_white());
    lv_style_set_line_rounded(&mStyle, false);
    lv_obj_add_style(mLine, &mStyle, 0);
}

Triangle::~Triangle()
{
    lv_obj_del(mLine);
}

void Triangle::setColor(lv_color_t color)
{
    lv_style_set_line_color(&mStyle, color);
}

const lv_obj_t* const Triangle::getLvObj() const noexcept
{
    return mLine;
}

