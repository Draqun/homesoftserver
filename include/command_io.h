#ifndef COMMAND_IO_H
#define COMMAND_IO_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "delay.h"

enum Command {
    CHANGE_CAMERA_ANGLE,
    GET_DEVICE_LAST_ERROR,
    INXPECT_DEVICES,
};

/**
* Run command listener to retrieve commands
*/
void* command_listener();

#endif // COMMAND_IO_H
