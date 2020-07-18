#ifndef DEVICES_H
#define DEVICES_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "camera.h"
#include "command_io.h"
#include "device_core.h"

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
*   Call correct action on device
*/
void device_action(enum Command c, size_t argc, ...);

/**
*   Get device error
*/
const char* get_device_last_error(device_core_t* device);

#endif // DEVICES_H
