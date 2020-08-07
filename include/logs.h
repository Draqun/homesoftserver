#ifndef LOGS_H
#define LOGS_H

#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256
#define LOG_SIZE 2048

#define LOG_MESSAGE(lvl, args...)\
        {\
        char log[LOG_SIZE];\
        sprintf(log, args);\
        add_log((const char*)&log, lvl);\
        }

enum LogLevel
{
    DEBUG = 1,
    INFO,
    WARNING,
    ERROR,
};

typedef struct buffer
{
    int index;
    char** buffer;
    enum LogLevel log_levels[BUFFER_SIZE];
} buffer_t;

extern volatile enum LogLevel log_level;

void* enable_logger(void *args);
void initilize_logger();
void add_log(const char *log, enum LogLevel level);
void disable_logger();

#endif // LOGS_H

