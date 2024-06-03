#include <mach/mach_time.h>
#include "utility/system_timer.h"
#include "types.h"



uint64 SystemTimer::GetTickCountSinceInitialization() {
    return (mach_absolute_time() / 1000000);
}