#ifndef PRIMORDIAL_CLIENT_STATUS_H
#define PRIMORDIAL_CLIENT_STATUS_H

#include "types.h"


enum ClientStatus : uint8 {
    Initialized = 0,
    InvalidSettingsFile = 1,
    LanguageFileNotFound = 2,
    InvalidLanguageFile = 3
};

std::string ClientStatusToString(ClientStatus status);


#endif
