#ifndef DEVICES_H
#define DEVICES_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "camera.h"
#include "commands.h"
#include "device_core.h"
#include "inspection.h"

#define CAMERAS 6
#define SENSORS 6
#define BEDROOMS 3
#define KITECHEN_CAMERA 0
#define BEDROOM_CAMERA_START 1
#define BEDROOM_CAMERA_STOP 4
#define DAILY_ROOM_CAMERA 4
#define GUEST_ROOM_CAMERA 5

extern camera_t camera[CAMERAS];
extern sensor_t sensor[SENSORS];

/**
*   Function to initialize devices
*/
void initialize_devices();

/**
*   Call correct action on device
*/
void* device_action(void *args);

#endif // DEVICES_H
