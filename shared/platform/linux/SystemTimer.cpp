#include "utility/SystemTimer.h"
#include <sys/time.h>


uint64 SystemTimer::GetTickCountSinceInitialization() {
    uint64 ticks;
    struct timespec now;

    clock_gettime(CLOCK_MONOTONIC, &now);
    ticks = (now.tv_sec - start.tv_sec) * 1000 + (now.tv_nsec - start.tv_nsec) / 1000000;
    return (ticks);
}