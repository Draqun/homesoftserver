#include "../include/usserver.h"


int main() {
    pthread_t logger_thread;

    initilize_logger();
    char log[10][50];
    for (int i=0; i < 10; ++i)
    {
        sprintf(log[i], "%d %s", i, " - log");
        add_log(&log[i]);
    }
    disable_logger();

    pthread_create(&logger_thread, NULL, enable_logger, NULL);
    pthread_join(logger_thread, NULL);

    return 0;
}
