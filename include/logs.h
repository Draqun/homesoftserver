#ifndef LOGS_H
#define LOGS_H

#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* enable_logger();
void initilize_logger();
void add_log(const char *log);
void disable_logger();

#define BUFFER_SIZE 10
#define LOG_SIZE 128

typedef struct buffer {
    int index;
    char** buffer;
} buffer_t;

#endif // LOGS_H

