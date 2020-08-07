#ifndef DEVICES_H
#define DEVICES_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#include "camera.h"
#include "commands.h"
#include "device_core.h"
#include "inspection.h"
#include "sensor.h"

#define CAMERAS 6
#define SENSORS 8
#define BEDROOMS 3
#define KITECHEN 0
#define BEDROOM_START 1
#define BEDROOM_STOP 3
#define DAILY_ROOM 4
#define GUEST_ROOM 5
#define TOILET 6
#define BATHROOM 7

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
