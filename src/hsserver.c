#include "../include/hsserver.h"


int main() {
    pthread_t logger_thread, command_listener_thread;

    initilize_logger();
    initialize_devices();
    inspect_devices();

    pthread_create(&logger_thread, NULL, enable_logger, NULL);
    pthread_create(&command_listener_thread, NULL, command_listener, NULL);

    pthread_join(command_listener_thread, NULL);


    disable_logger();
    pthread_join(logger_thread, NULL);

    return 0;
}
