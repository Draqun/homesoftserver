#ifndef SLEEP_H
#define SLEEP_H

#include<unistd.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #define DELAY(time) (usleep(time*100000))
#else
    #define DELAY(time) (sleep(time))
#endif

#endif // SLEEP_H
