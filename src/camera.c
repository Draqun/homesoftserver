#include "../include/camera.h"

void initialize_camera(camera_t* camera, const char* id, int x, int y, int z)
{
    LOG_MESSAGE("Starting camera initialization: %s", id)

    camera->x_angle = x;
    camera->y_angle = y;
    camera->z_angle = z;
    strcpy(((device_core_t*)camera)->id, id);
    ((device_core_t*)camera)->enabled = true;
}

void change_camera_angles(camera_t* camera, int x, int y, int z)
{
    LOG_MESSAGE("Changes camera %s angles into: %d %d %d", ((device_core_t*)camera)->id, x, y, z)

    camera->x_angle = x;
    camera->y_angle = y;
    camera->z_angle = z;
}
