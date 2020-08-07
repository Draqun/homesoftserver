#include "../include/devices.h"

/**
*   Table with room numbers
*   0 - kitchen
*   1-3 - bedrooms
*   4 - daily room
*   5 - guest room
*/
camera_t camera[CAMERAS] = {CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT};
sensor_t sensor[SENSORS] = {SENSOR_INIT, SENSOR_INIT, SENSOR_INIT, SENSOR_INIT, SENSOR_INIT, SENSOR_INIT, SENSOR_INIT};

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
    char sensor_id[DEVICE_ID_SIZE];

    if (!camera[KITECHEN].core.enabled)
    {
        sprintf(camera_id, "0x00%d", KITECHEN);
        sprintf(sensor_id, "0x00%d", KITECHEN);
        initialize_camera(&camera[KITECHEN], camera_id, 90, -45, -45);
        initialize_sensor(&sensor[KITECHEN], sensor_id, 38, 2);
    }

    for (int i = BEDROOM_START; i <= BEDROOM_STOP; ++i)
    {
        if (camera[i].core.enabled) continue;

        sprintf(camera_id, "0x00%d", i);
        sprintf(sensor_id, "0x00%d", i);
        initialize_camera(&camera[i], camera_id, 45, -45, -35);
        initialize_sensor(&sensor[i], sensor_id, 30, 2);
    }

    if (!camera[DAILY_ROOM].core.enabled)
    {
        sprintf(camera_id, "0x00%d", DAILY_ROOM);
        sprintf(sensor_id, "0x00%d", DAILY_ROOM);
        initialize_camera(&camera[DAILY_ROOM], camera_id, 90, -45, -45);
        initialize_sensor(&sensor[DAILY_ROOM], sensor_id, 30, 3);
    }

    if (!camera[GUEST_ROOM].core.enabled)
    {
        sprintf(camera_id, "0x00%d", GUEST_ROOM);
        sprintf(sensor_id, "0x00%d", GUEST_ROOM);
        initialize_camera(&camera[GUEST_ROOM], camera_id, 90, -45, -45);
        initialize_sensor(&sensor[GUEST_ROOM], sensor_id, 30, 3);
    }

    sprintf(sensor_id, "0x00%d", TOILET);
    initialize_sensor(&sensor[TOILET], sensor_id, 30, 3);
    sprintf(sensor_id, "0x00%d", BATHROOM);
    initialize_sensor(&sensor[BATHROOM], sensor_id, 40, 4);

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

        LOG_MESSAGE(DEBUG, "Getting device %s last error", id);
        sprintf(dest, get_device_last_error((device_core_t*)get_device_by_id(id)));
        break;
        }

    case GET_DEVICES_STATUS: {
        char **device_log = va_arg(*argv, char **);
        LOG_MESSAGE(DEBUG, "Getting devices status");
        get_cameras_status(device_log);
        break;
        }

    case GET_SENSORS_STATUS: {
        char **device_log = va_arg(*argv, char **);
        LOG_MESSAGE(DEBUG, "Getting sensors status");
        get_sensors_status(device_log);
        break;
        }

    default:
        LOG_MESSAGE(ERROR, "Given command is not handled yet!");
    };
    va_end(*argv);
    return (void*)NULL;
}
