#ifndef COMMAND_IO_H
#define COMMAND_IO_H

#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "delay.h"
#include "device_core.h"
#include "logs.h"

enum Command {
    CHANGE_CAMERA_ANGLES,
    GET_DEVICE_LAST_ERROR,
    INXPECT_DEVICES,
};

enum DeviceType {
    CAMERA,
};

/**
*   Run command listener to retrieve commands
*/
void* command_listener();

#endif // COMMAND_IO_H
