#include "../include/devices.h"

/**
* Table with camera devices
* 0 - kitchen camera
* 1-3 - bedrooms cameras
* 4 - daily room camera
* 5 - guest room camera
*/
volatile camera_t camera[CAMERAS] = {CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT, CAMERA_INIT};

void initialize_devices()
{
    add_log("Starting devices initialization");
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
    add_log("Devices initialized");
}
