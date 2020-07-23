#ifndef COMMAND_IO_H
#define COMMAND_IO_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "commands.h"
#include "delay.h"
#include "device_core.h"
#include "devices.h"
#include "logs.h"


/**
*   Run command listener to retrieve commands
*/
void *command_listener(void *args);

/**
*   Run command as a parallel task
*/
void run_task(size_t argc, ...);

#endif // COMMAND_IO_H
