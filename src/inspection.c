#include "../include/inspection.h"

void inspect_devices()
{
    for (int i = 0; i < CAMERAS; ++i)
    {
        if (!camera[i].core.enabled)
        {
            strcpy(camera[i].core.error_msg, "Camera is not enabled");
            char message[LOG_SIZE];
            sprintf(message, "Camera with id %s is disabled!", camera[i].core.id);
            add_log(message);
        }
    }
}
