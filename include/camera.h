#ifndef CAMERA_H
#define CAMERA_H

#include <stdbool.h>

#define CAMERA_ID_SIZE 64
#define CAMERA_INIT {.x_angle = 0, .y_angle = 0, .z_angle = 0, .id = "", .enabled = false, .error_msg = ""}

typedef struct camera_s {
    int x_angle;
    int y_angle;
    int z_angle;
    char id[CAMERA_ID_SIZE];
    bool enabled;
    char error_msg[128];
} camera_t;

#endif // CAMERA_H
