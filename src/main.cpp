#include <stdio.h>
#include <libdragon.h>
#include <GL/gl.h>

#include "Game/Game.hpp"

int main(void)
{
    Game game;
    timer_init();
    Inputs::Init();
    display_init(RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, FILTERS_RESAMPLE);
    console_init();

    rdpq_init();
    gl_init();

    debug_init_usblog();
    console_set_debug(true);

    game.Init();
    while(1) {
        // Update
        Inputs::Update();
        game.Update();
        // Render
        game.Render();
    }
}