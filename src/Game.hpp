#pragma once

#include <libdragon.h>

#include "Entity.hpp"
#include "Inputs.hpp"
#include "Vector3f.hpp"

class Game {
public:
    void Init();
    void Update();
    void Render();
};