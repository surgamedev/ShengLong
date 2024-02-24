#include <stdio.h>

#include <libdragon.h>

#include "Vector3f.hpp"
#include "Entity.hpp"

Entity entities[2] = {
    { {10, 10, 0}, 10, 10, {255, 0, 0, 255} },
    { {20, 20, 0}, 10, 10, {0, 0, 255, 255} }
};

int main(void)
{
    timer_init();
    joypad_init();
    display_init(RESOLUTION_320x240, DEPTH_16_BPP, 2, GAMMA_NONE, FILTERS_RESAMPLE);
    console_init();

    debug_init_usblog();
    console_set_debug(true);

    joypad_inputs_t inputs;

    while(1) {
        // Update
        joypad_poll();

        inputs = joypad_get_inputs(JOYPAD_PORT_1);

        Vector3f inputVector;

        if (inputs.btn.d_left)
        {
            inputVector.x -= 1;
        }

        if (inputs.btn.d_right)
        {
            inputVector.x += 1;
        }

        if (inputs.btn.d_up)
        {
            inputVector.y -= 1;
        }

        if (inputs.btn.d_down)
        {
            inputVector.y += 1;
        }

        entities[0].position += inputVector;
        // Render
        surface_t* disp = display_get();
        graphics_fill_screen(disp, 0x00000000);

        for(int i = 0; i < 2; i++) {
            Entity* entity = &entities[i];
            entity->Render(disp);
        }

        display_show(disp);
    }
}