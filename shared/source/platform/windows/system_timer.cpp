#include "windows.h"
#include "utility/system_timer.h"
#include "types.h"



uint64 SystemTimer::GetTickCountSinceInitialization() {
    return GetTickCount();
}