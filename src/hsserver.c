#include "../include/hsserver.h"


int main()
{
    pthread_t logger_thread, command_listener_thread, initialize_devices_thread;
    log_level = INFO;

    initilize_logger();
    pthread_create(&initialize_devices_thread, NULL, initialize_devices, NULL);
    pthread_create(&logger_thread, NULL, enable_logger, NULL);
    pthread_create(&command_listener_thread, NULL, command_listener, NULL);

    pthread_join(initialize_devices_thread, NULL);
    pthread_join(command_listener_thread, NULL);
    pthread_join(logger_thread, NULL);

    return 0;
}
