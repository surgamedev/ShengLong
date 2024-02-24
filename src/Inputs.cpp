#include "Inputs.hpp"

joypad_inputs_t Inputs::inputs[4];

void Inputs::Init()
{
    joypad_init();
}

void Inputs::Update()
{
    joypad_poll();
    inputs[0] = joypad_get_inputs(JOYPAD_PORT_1);
    inputs[1] = joypad_get_inputs(JOYPAD_PORT_2);
    inputs[2] = joypad_get_inputs(JOYPAD_PORT_3);
    inputs[3] = joypad_get_inputs(JOYPAD_PORT_4);
}

joypad_inputs_t Inputs::GetInput(short port)
{
    return inputs[port - 1];
}