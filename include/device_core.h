#ifndef DEVICE_CORE
#define DEVICE_CORE

#define DEVICE_ID_SIZE 64
#define DEVICE_ERROR_MSG_SIZE 128

typedef struct device_core_s {
    char id[DEVICE_ID_SIZE];
    bool enabled;
    char error_msg[DEVICE_ERROR_MSG_SIZE];
} device_core_t;

#endif // DEVICE_CORE
