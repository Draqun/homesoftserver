#include "../include/command_io.h"

volatile bool listener_is_running = true;

void* command_listener() {
    while (listener_is_running) {
        DELAY(9);
        // This task should be run in new threads
        device_action(CHANGE_CAMERA_ANGLES, 4, "0x000", 0, 0, 0);

        char error_msg[DEVICE_ERROR_MSG_SIZE];
        device_action(GET_DEVICE_LAST_ERROR, 2, &error_msg, "0x001");
        LOG_MESSAGE("Error message: %s", error_msg);
    }
    return (void*)NULL;
}
