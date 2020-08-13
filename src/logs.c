#include "../include/logs.h"

volatile bool disable_logger_flag = false;
pthread_mutex_t log_m, flag_m, buf_index_m;
volatile buffer_t logger;
volatile enum LogLevel log_level = DEBUG;

const char *log_lvl_str[4] =
{
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
};

void initilize_logger()
{
    logger.buffer = (char**)malloc(sizeof(char*)*BUFFER_SIZE);
    logger.index = -1;
    for (int i = 0; i < BUFFER_SIZE; ++i) logger.buffer[i] = (char*)NULL, logger.log_levels[i] = DEBUG;
}

void* enable_logger(void *args)
{
    pthread_mutex_lock(&flag_m);
    while (!disable_logger_flag || logger.index >= 0)
    {
        if (logger.index >= 0)
        {
            pthread_mutex_lock(&log_m);
            pthread_mutex_lock(&buf_index_m);
            for (int i = 0; i <= logger.index; ++i)
            {
                if (logger.buffer[i] != (char*)NULL)
                {
                    const size_t log_lvl_str_index = (size_t)logger.log_levels[i] - 1;
                    printf("LOG:%s:%s\n", log_lvl_str[log_lvl_str_index], logger.buffer[i]);
                    free(logger.buffer[i]);
                    logger.buffer[i] = (char*)NULL;
                }
            }
            logger.index = -1;
            pthread_mutex_unlock(&buf_index_m);
            pthread_mutex_unlock(&log_m);
        }
    }
    pthread_mutex_unlock(&flag_m);

    pthread_mutex_lock(&log_m);
    free(logger.buffer);
    pthread_mutex_unlock(&log_m);

    return (void*)NULL;
}

void add_log(const char *log, enum LogLevel level)
{
    char *llog = (char*)malloc(sizeof(char)*strlen(log));
    strcpy(llog, log);
    if (logger.index >= BUFFER_SIZE || log_level > level) return;

    pthread_mutex_lock(&buf_index_m);
    pthread_mutex_lock(&log_m);

    ++logger.index;
    logger.buffer[logger.index % BUFFER_SIZE] = llog;
    logger.log_levels[logger.index % BUFFER_SIZE] = level;
    logger.index = logger.index % BUFFER_SIZE;

    pthread_mutex_unlock(&buf_index_m);
    pthread_mutex_unlock(&log_m);
}

void disable_logger()
{
    pthread_mutex_lock(&flag_m);
    disable_logger_flag = true;
    pthread_mutex_unlock(&flag_m);
}
