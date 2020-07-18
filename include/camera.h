#ifndef CAMERA_H
#define CAMERA_H

#include <stdbool.h>

#include "device_core.h"
#include "logs.h"

#define CAMERA_INIT {{.id = "", .enabled = false, .error_msg = ""}, .x_angle = 0, .y_angle = 0, .z_angle = 0}

typedef struct camera_s {
    device_core_t core;
    int x_angle;
    int y_angle;
    int z_angle;
} camera_t;

/**
*   Function initialize camera position and enable it.
*/
void initialize_camera(camera_t* camera, const char* id, int x, int y, int z);

/**
*   Change camera angles
*/
void change_camera_angles(camera_t* camera, int x, int y, int z);

#endif // CAMERA_H
