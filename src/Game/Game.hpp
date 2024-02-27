#pragma once

#include <libdragon.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/gl_integration.h>
#include <array>

#include "../Engine/Entity.hpp"
#include "../Engine/Inputs.hpp"
#include "../Engine/Math/Vector3f.hpp"

class Game {
public:
    void Init();
    void Update();
    void Render();
};