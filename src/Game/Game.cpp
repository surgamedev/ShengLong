#include "Game.hpp"

Engine::Entity entities[2] = {
    {{10, 10, 0}, 10, 10, {255, 0, 0, 255}},
    {{20, 20, 0}, 10, 10, {0, 0, 255, 255}}};

float rotation = 0.0f;

void Game::Init()
{
    float aspect_ratio = (float)display_get_width() / (float)display_get_height();
    float near_plane = 0.1f;
    float far_plane = 50.0f;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-near_plane * aspect_ratio, near_plane * aspect_ratio, -near_plane, near_plane, near_plane, far_plane);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    float ambientLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

    float material[] = {1.0f, 1.0f, 1.0f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material);

    glFogf(GL_FOG_START, 5);
    glFogf(GL_FOG_END, 20);
    glFogfv(GL_FOG_COLOR, ambientLight);

    glEnable(GL_MULTISAMPLE_ARB);
}

void Game::Update()
{
    rotation += 0.75f;
    if(rotation > 360.0f) {
        rotation = 0.0f;
    }
}

void Game::Render()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 10, 10, 0, 0, 0, 0, 1, 0);

    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);

    glPushMatrix();
    glTranslatef(0.0f, -1.0f, 0.0f);
    glRotatef(rotation, 1, 0, 1);
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