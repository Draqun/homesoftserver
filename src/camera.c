#include "../include/camera.h"


void initialize_camera(camera_t* camera, const char* id, int x, int y, int z)
{
    {
        char log[LOG_SIZE] = "Starting camera initialization: ";
        strcat(log, id);
        add_log(&log);
    }

    camera->x_angle = x;
    camera->y_angle = y;
    camera->z_angle = z;
    strcpy(((device_core_t*)camera)->id, id);
    ((device_core_t*)camera)->enabled = true;
}
