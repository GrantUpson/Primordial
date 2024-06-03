#ifndef PRIMORDIAL_SYSTEM_TIMER_H
#define PRIMORDIAL_SYSTEM_TIMER_H

#include "types.h"


class SystemTimer {
public:
    SystemTimer() = default;
    ~SystemTimer() = default;

    static uint64 GetTickCountSinceInitialization();
};

#endif
