#include "Entity.hpp"

using namespace Engine;

void Entity::Update() {
    this->rotation += 0.75f;
    if(this->rotation > 360.0f) {
        this->rotation = 0.0f;
    }
}

void Entity::Render() const
{
    glPushMatrix();
    glTranslatef(this->position.x, this->position.y, this->position.z);
    glRotatef(this->rotation, 1, 0, 1);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glVertexPointer(3, GL_FLOAT, sizeof(vertex_t), reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(cube_vertices) + 0 * sizeof(float)));
    glTexCoordPointer(2, GL_FLOAT, sizeof(vertex_t), reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(cube_vertices) + 3 * sizeof(float)));
    glNormalPointer(GL_FLOAT, sizeof(vertex_t), reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(cube_vertices) + 5 * sizeof(float)));
    glColorPointer(4, GL_UNSIGNED_BYTE, sizeof(vertex_t), reinterpret_cast<void *>(reinterpret_cast<uintptr_t>(cube_vertices) + 8 * sizeof(float)));

    glDrawElements(GL_TRIANGLES, sizeof(cube_indices) / sizeof(uint16_t), GL_UNSIGNED_SHORT, cube_indices);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);

    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
}