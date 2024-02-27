#pragma once

#include <libdragon.h>

class Inputs {
private:
    static joypad_inputs_t inputs[4];
public:
    static void Init();
    static void Update();

    static joypad_inputs_t GetInput(short port);
};