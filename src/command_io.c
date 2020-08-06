#include "../include/command_io.h"

volatile bool listener_is_running = true;

void *command_listener(void *args)
{
    while (listener_is_running)
    {
        {
            DELAY(9);
            run_task(5, CHANGE_CAMERA_ANGLES, "0x000", 0, 0, 0);
        }

        {
            DELAY(9);
            char error_msg[DEVICE_ERROR_MSG_SIZE];
            run_task(3, GET_DEVICE_LAST_ERROR, &error_msg, "0x001");
            if (strcmp(error_msg, ""))
            {
                LOG_MESSAGE(ERROR, "Error message: %s", error_msg);
            }
        }

        {
            DELAY(9);
            char **devices_status = (char**)NULL;
            {
            run_task(2, GET_DEVICES_STATUS, devices_status);
            LOG_MESSAGE(DEBUG, "Devices inspected");
            }
            for (int i=0; i < CAMERAS && devices_status && devices_status[i]; ++i)
            {
                printf("%s", devices_status[i]);
                free(devices_status[i]);
            }
            free(devices_status);
        }

        {
            DELAY(9);
            char **sensors_status = (char**)NULL;
            run_task(2, GET_SENSORS_STATUS, sensors_status);
            LOG_MESSAGE(DEBUG, "Sensors inspected");

        }
    }
    return (void*)NULL;
}

void run_task(size_t argc, ...)
{
    va_list argv;
    va_start(argv, argc);

    pthread_t task_thread;

    pthread_create(&task_thread, NULL, device_action, (void*)&argv);
    pthread_join(task_thread, NULL);
}
