#include "../include/usserver.h"


int main() {
    pthread_t logger;

    initilize_logger();
    pthread_create(&logger, NULL, enable_logger, NULL);
    char log[10][50];
    for (int i=0; i < 10; ++i)
    {
        sprintf(log[i], "%d %s", i, " - log");
        add_log(&log[i]);
    }
    disable_logger();
    pthread_join(logger, NULL);

    return 0;
}
