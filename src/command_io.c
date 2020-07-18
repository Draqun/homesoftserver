#include "../include/command_io.h"

volatile bool listener_is_running = true;

void* command_listener() {
    while (listener_is_running) {
        DELAY(1);
    }
    return (void*)NULL;
}
