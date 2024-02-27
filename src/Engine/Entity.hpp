#pragma once

#include <libdragon.h>
#include "Math/Vector3f.hpp"

namespace Engine
{
    class Entity
    {
    public:
        Math::Vector3f position;
        int width;
        int height;
        color_t color;

        Entity(Math::Vector3f position, int width, int height, color_t color) : position{position}, width{width}, height{height}, color{color} {};

        void Render(surface_t *disp);
    };
}