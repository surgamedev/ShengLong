#include "Entity.hpp"

void Entity::Render(surface_t *disp)
{
    uint32_t color = graphics_convert_color(this->color);
    graphics_draw_box(disp, this->position.x, this->position.y, this->width, this->height, color);
}