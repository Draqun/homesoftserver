#include "../include/devices.h"

/**
* Table with camera devices
* 0 - kitchen camera
* 1-3 - bedrooms cameras
* 4 - daily room camera
* 5 - guest room camera
*/
volatile camera_t camera[CAMERAS] = {CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT};

/**
*   Static function to find device by it ID
*/
static camera_t* get_device_by_id(const char *id)
{
    LOG_MESSAGE("Searching device with id: %s", id);
    for (int i = 0; i < CAMERAS; ++i)
    {
        if (0 == strcmp(id, camera[i].core.id))
        {
            LOG_MESSAGE("Device found!");
            return &camera[i];
        }
    }
    LOG_MESSAGE("Device not found!");
}

void initialize_devices()
{
    LOG_MESSAGE("Starting devices initialization");
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
    LOG_MESSAGE("Devices initialized");
}

void device_action(enum Command c, size_t argc, ...)
{
    va_list argv;
    va_start(argv, argc);

    switch (c)
    {
    case CHANGE_CAMERA_ANGLES: {
        const char* id= va_arg(argv, const char *);
        change_camera_angles(get_device_by_id(id), va_arg(argv, int), va_arg(argv, int), va_arg(argv, int));
        break;
        }

    case GET_DEVICE_LAST_ERROR: {
        char* dest = va_arg(argv, const char *);
        const char* id = va_arg(argv, const char *);

        sprintf(dest, get_device_last_error(get_device_by_id(id)));
        break;
        }

    default:
        LOG_MESSAGE("Given command is not handled yet!");
    }
    va_end(argv);
}

const char* get_device_last_error(device_core_t* device)
{
    return device->error_msg;
}
