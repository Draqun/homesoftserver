#include "../include/inspection.h"

void get_cameras_status(char **devices_log)
{
    LOG_MESSAGE(DEBUG, "Getting devices status");
    devices_log = (char**)malloc(sizeof(char*)*CAMERAS);
    if (!devices_log)
    {
        return;
    }

    for (int i = 0; i < CAMERAS; ++i)
    {
        char device_status[LOG_SIZE];
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

        devices_log[i] = (char*)malloc(sizeof(char)*LOG_SIZE);
        if (!devices_log[i])
        {
            LOG_MESSAGE(ERROR, "Cannot allocate enough memory for camera with id %s", sensor[i].core.id)
            continue;
        }

        sprintf(devices_log[i], "Camera %s is %s", camera[i].core.id, device_status);
    }
}

void get_sensors_status(char **sensors_log)
{
    LOG_MESSAGE(DEBUG, "Getting sensors status");
    sensors_log  = (char**)malloc(sizeof(char*)*SENSORS);
    if (!sensors_log)
    {
        return;
    }

    for (int i = 0; i < SENSORS; ++i)
    {
        char device_status[LOG_SIZE];
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

        sensors_log[i] = (char*)malloc(sizeof(char)*LOG_SIZE);
        if (!sensors_log[i])
        {
            LOG_MESSAGE(ERROR, "Cannot allocate enough memory for sensor with id %s", sensor[i].core.id)
            continue;
        }

        sprintf(sensors_log[i], "Sensor %s is %s", sensor[i].core.id, device_status);
        printf("%s\n", sensors_log[i]);
    }
}
