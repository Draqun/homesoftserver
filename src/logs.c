#include "../include/logs.h"

volatile bool disable_logger_flag = false;
pthread_mutex_t log_m, flag_m;
volatile buffer_t logger;

void initilize_logger() {
    logger.buffer = (char**)malloc(sizeof(char*)*BUFFER_SIZE);
    logger.index = -1;
    for (int i = 0; i < BUFFER_SIZE; ++i) logger.buffer[i] = (char*)NULL;
}

void* enable_logger() {
    puts("Start logging\n");

    pthread_mutex_lock(&flag_m);\
    while (!disable_logger_flag || logger.index >= 0) {
        if (logger.index >= 0) {
            pthread_mutex_lock(&log_m);
            for (int i = 0; i <= logger.index; ++i) {
                if (logger.buffer[i] != (char*)NULL) {
                    printf("LOG: %s\n", logger.buffer[i]);
                    free(logger.buffer[i]);
                    logger.buffer[i] = (char*)NULL;
                }
            }
            logger.index = -1;
            pthread_mutex_unlock(&log_m);
        }
    }
    pthread_mutex_unlock(&flag_m);
    free(logger.buffer);
    return (void*)NULL;
}

void add_log(const char *log) {
    char *llog = (char*)malloc(sizeof(char)*strlen(log));
    strcpy(llog, log);
    if (logger.index >= BUFFER_SIZE) return;

    pthread_mutex_lock(&log_m);

    logger.buffer[++logger.index % BUFFER_SIZE] = llog;
    logger.index = logger.index % BUFFER_SIZE;
    pthread_mutex_unlock(&log_m);
}

void disable_logger() {
    pthread_mutex_lock(&flag_m);
    disable_logger_flag = true;
    pthread_mutex_unlock(&flag_m);
}
