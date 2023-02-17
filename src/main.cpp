#include "lvgl.h"
#include <cstdint>
#include <SDL.h>

#define WIDTH 320
#define HEIGHT 240

static lv_color_t buffer[WIDTH * HEIGHT];
static lv_disp_drv_t displayDriver;
static lv_disp_draw_buf_t displayBuffer;
static lv_disp_t* disp = nullptr;

void flush(lv_disp_drv_t* drv, const lv_area_t* area, lv_color_t* color_p)
{
    int32_t x, y;
    for(y = area->y1; y <= area->y2; y++) {
        for(x = area->x1; x <= area->x2; x++) {
            buffer[(y * WIDTH) + x].full = color_p->full;
            color_p++;
        }
    }
    lv_disp_flush_ready(drv);
}

void initDisplayDriver()
{
    lv_init();
    lv_disp_draw_buf_init(&displayBuffer, buffer, nullptr, WIDTH * HEIGHT);
    lv_disp_drv_init(&displayDriver); 
    displayDriver.draw_buf = &displayBuffer;   
    displayDriver.flush_cb = flush;
    displayDriver.hor_res = WIDTH;               
    displayDriver.ver_res = HEIGHT;               

    disp = lv_disp_drv_register(&displayDriver);
}

int main()
{
    initDisplayDriver();

    // LVGL stuff
    lv_color_fill(buffer, lv_color_white(), WIDTH * HEIGHT);               

    auto* window = SDL_CreateWindow("Title", 0, 0, WIDTH, HEIGHT, 0);
    auto* windowSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(windowSurface, nullptr, SDL_MapRGB(windowSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
    
    // Display Lvgl Buffer
    auto* surface = SDL_CreateRGBSurfaceFrom(buffer, WIDTH, HEIGHT, 32, 4 * WIDTH, 0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000);
    SDL_BlitScaled(surface, nullptr, windowSurface, nullptr);
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(surface);

    while (1) {}

    return 0;
}