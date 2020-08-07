#include "../include/sensor.h"

void initialize_sensor(sensor_t* sensor, const char* id, int value, int offset)
{
    LOG_MESSAGE(INFO, "Starting initialization sensor: %s", id);

    sensor->value = value;
    sensor->last_incorrect_value = 0;
    sensor->offset = offset;
    strcpy(((device_core_t*)sensor)->id, id);
    //strcpy(((device_core_t*)sensor)->error_msg, "TEST");  // Uncomment for test
    ((device_core_t*)sensor)->enabled = true;
}
