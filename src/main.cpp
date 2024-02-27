#include <stdio.h>
#include <libdragon.h>
#include <GL/gl.h>

#include "Game/Game.hpp"

int main(void)
{
    timer_init();
    Engine::Inputs::Init();
    display_init(RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, FILTERS_RESAMPLE);
    console_init();
    Game game;

    rdpq_init();
    gl_init();

    debug_init_usblog();
    console_set_debug(true);
    surface_t zbuffer = surface_alloc(FMT_RGBA16, display_get_width(), display_get_height());

    game.Init();
    while(1) {
        // Update
        Engine::Inputs::Update();
        game.Update();

        // Render
        surface_t *disp = display_get();
        rdpq_attach(disp, &zbuffer);
        gl_context_begin();

        game.Render();

        gl_context_end();
        rdpq_detach_show();
    }
}