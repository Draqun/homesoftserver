#ifndef SENSOR_H
#define SENSOR_H

#include "device_core.h"
#include "logs.h"

#define SENSOR_INIT {{.id = "", .enabled = false, .error_msg = ""}, .offset = 0, .value = 0, .last_incorrect_value = 0}

typedef struct sensor_s
{
    device_core_t core;
    size_t offset;
    int value;
    int last_incorrect_value;
} sensor_t;

/**
*   Function initialize sensors enable it.
*/
void initialize_sensor(sensor_t* sensor, const char* id, int value, int offset);

#endif // SENSOR_H
