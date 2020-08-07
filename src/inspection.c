#include "../include/inspection.h"

void get_cameras_status(char *cameras_log)
{
    LOG_MESSAGE(DEBUG, "Getting devices status");
    const size_t status_msg_size = 16;
    char device_status[status_msg_size];

    for (int i = 0; i < CAMERAS; ++i)
    {
        char camera_log[LOG_SIZE];
        if (!camera[i].core.enabled)
        {
            strcpy(device_status, "disabled");
            strcpy(camera[i].core.error_msg, "Camera is not enabled");
            LOG_MESSAGE(INFO, "Camera with id %s is disabled!", camera[i].core.id);
        }
        else
        {
            strcpy(device_status, "enabled");
        }

        sprintf(camera_log, "Camera %s is %s - X=%d Y=%d Z=%d\n", camera[i].core.id, device_status, camera[i].x_angle, camera[i].y_angle, camera[i].z_angle);
        strcat(cameras_log, camera_log);
    }
}

void get_sensors_status(char *sensors_log)
{
    LOG_MESSAGE(DEBUG, "Getting sensors status");
    const size_t status_msg_size = 16;
    char device_status[status_msg_size];

    for (size_t i = 0; i < SENSORS; ++i)
    {
        char sensor_log[LOG_SIZE];
        if (!sensor[i].core.enabled)
        {
            strcpy(device_status, "disabled");
            strcpy(sensor[i].core.error_msg, "Sensor is not enabled");
            LOG_MESSAGE(INFO, "Sensor with id %s is disabled!", sensor[i].core.id);
        }
        else
        {
            strcpy(device_status, "enabled");
        }

        sprintf(sensor_log, "Sensor %s is %s - Current value=%d Offset=%d Last incorrect value=%d \n", sensor[i].core.id, device_status, sensor[i].value, sensor[i].offset, sensor[i].last_incorrect_value);
        strcat(sensors_log, sensor_log);
    }
}
