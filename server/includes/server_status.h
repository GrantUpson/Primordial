#ifndef PRIMORDIAL_SERVER_STATUS_H
#define PRIMORDIAL_SERVER_STATUS_H

#include "types.h"


enum ServerStatus : uint8 {
    Initialized = 0,
    SettingsFileNotFound = 1,
    InvalidSettingsFile = 2,
    MemoryAllocationFailure = 3
};

std::string ServerStatusToString(ServerStatus status);


#endif
