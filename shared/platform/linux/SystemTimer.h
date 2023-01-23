#ifndef PRIMORDIAL_SYSTEMTIMER_H
#define PRIMORDIAL_SYSTEMTIMER_H

#include "utility/Utility.h"


class SystemTimer {
public:
    SystemTimer() = default;
    ~SystemTimer() = default;

    static uint64 GetTickCountSinceInitialization();
};


#endif
