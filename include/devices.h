#ifndef DEVICES_H
#define DEVICES_H

#include <stdio.h>
#include <string.h>

#include "camera.h"
#include "logs.h"

#define CAMERAS 6
#define BEDROOMS 3
#define KITECHEN_CAMERA 0
#define BEDROOM_CAMERA_START 1
#define BEDROOM_CAMERA_STOP 4
#define DAILY_ROOM_CAMERA 4
#define GUEST_ROOM_CAMERA 5

extern volatile camera_t camera[CAMERAS];

/**
*   Function to initialize devices
*/
void initialize_devices();

/**
* Function initialize camera position and enable it.
*/
void initialize_camera(camera_t* camera, const char* id, int x, int y, int z);

#endif // DEVICES_H
