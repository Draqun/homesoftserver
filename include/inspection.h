#ifndef INSPECTION_H
#define INSPECTION_H

#include <stdio.h>

#include "devices.h"
#include "logs.h"

/**
*   Get all cameras status
*/
void get_cameras_status(char *cameras_log);

/**
*   Get all sensors status
*/
void get_sensors_status(char *sensors_log);

#endif // INSPECTION_H
