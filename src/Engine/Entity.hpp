#pragma once

#include <libdragon.h>
#include "Math/Vector3f.hpp"

class Entity{
public:
    Vector3f position;
    int width;
    int height;
    color_t color;

    Entity(Vector3f position, int width, int height, color_t color) : 
        position{position}, width{width}, height{height}, color{color} {};

    void Render(surface_t *disp);
};