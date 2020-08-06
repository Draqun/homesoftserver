#include "../include/devices.h"

/**
*   Table with camera devices
*   0 - kitchen camera
*   1-3 - bedrooms cameras
*   4 - daily room camera
*   5 - guest room camera
*/
camera_t camera[CAMERAS] = {CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT};
sensor_t sensor[SENSORS] = {SENSOR_INIT, SENSOR_INIT, SENSOR_INIT, SENSOR_INIT, SENSOR_INIT, SENSOR_INIT};

static const char* get_device_last_error(device_core_t* device)
{
    return device->error_msg;
}

/**
*   Static function to find device by it ID
*/
static camera_t* get_device_by_id(const char *id)
{
    LOG_MESSAGE(DEBUG, "Searching device with id: %s", id);
    for (int i = 0; i < CAMERAS; ++i)
    {
        if (0 == strcmp(id, camera[i].core.id))
        {
            LOG_MESSAGE(DEBUG, "Device found!");
            return &camera[i];
        }
    }
    LOG_MESSAGE(WARNING, "Device not found!");
    return (camera_t*)NULL;
}

void initialize_devices()
{
    LOG_MESSAGE(INFO, "Starting devices initialization");
    char camera_id[DEVICE_ID_SIZE];

    if (!camera[KITECHEN_CAMERA].core.enabled)
    {
        sprintf(camera_id, "0x00%d", 0);
        initialize_camera(&camera[KITECHEN_CAMERA], camera_id, 90, -45, -45);
    }

    for (int i = BEDROOM_CAMERA_START; i < BEDROOM_CAMERA_STOP; ++i)
    {
        if (camera[i].core.enabled) continue;

        sprintf(camera_id, "0x00%d", i);
        initialize_camera(&camera[i], camera_id, 45, -45, -35);
    }

    if (!camera[DAILY_ROOM_CAMERA].core.enabled)
    {
        sprintf(camera_id, "0x00%d", DAILY_ROOM_CAMERA);
        initialize_camera(&camera[DAILY_ROOM_CAMERA], camera_id, 90, -45, -45);
    }

    if (!camera[GUEST_ROOM_CAMERA].core.enabled)
    {
        sprintf(camera_id, "0x00%d", GUEST_ROOM_CAMERA);
        initialize_camera(&camera[GUEST_ROOM_CAMERA], camera_id, 90, -45, -45);
    }
    LOG_MESSAGE(INFO, "Devices initialized");
}

void* device_action(void *args)
{
    va_list *argv = (va_list*)args;

    enum Command c = va_arg(*argv, enum Command);

    switch (c)
    {
    case CHANGE_CAMERA_ANGLES: {
        const char* id = va_arg(*argv, const char *);
        change_camera_angles(get_device_by_id(id), va_arg(*argv, int), va_arg(*argv, int), va_arg(*argv, int));
        break;
        }

    case GET_DEVICE_LAST_ERROR: {
        char *dest = va_arg(*argv, const char *);
        const char* id = va_arg(*argv, const char *);

        sprintf(dest, get_device_last_error((device_core_t*)get_device_by_id(id)));
        break;
        }

    case GET_DEVICES_STATUS: {
        char **device_log = va_arg(*argv, char **);
        //LOG_MESSAGE(DEBUG, "Start of inspecting device");
        inspect_devices(device_log);
        LOG_MESSAGE(DEBUG, "End of inspecting device");
        break;
        }

    default:
        LOG_MESSAGE(ERROR, "Given command is not handled yet!");
    };
    va_end(*argv);
    return (void*)NULL;
}
