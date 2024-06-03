#include "server_status.h"


std::string ServerStatusToString(ServerStatus status) {
    switch(status) {
        case Initialized:
            return "Code [0]: Server initialized successfully";
        case SettingsFileNotFound:
            return "Code [1]: Settings file not found";
        case InvalidSettingsFile:
            return "Code [2]: Invalid settings file, it may be corrupted";
        case MemoryAllocationFailure:
            return "Code [3]: Failed to allocate the initial memory pool";
    }
}