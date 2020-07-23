#include "../include/inspection.h"

void inspect_devices(char **device_log)
{
    device_log = (char**)malloc(sizeof(char*)*CAMERAS);
    if (device_log != NULL)
    {
        return;
    }

    for (int i = 0; i < CAMERAS; ++i)
    {
        char device_status[128];
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
        device_log[i] = (char*)malloc(sizeof(char)*LOG_SIZE);
        sprintf(device_log[i], "Device %s is %s", camera[i].core.id, device_status);
    }
}
