#include "server_status.h"


std::string ServerStatusToString(ServerStatus status) {
    switch(status) {
        case Initialized:
            return "Code [0]: Server initialized successfully";
        case ConfigFileNotFound:
            return "Code [1]: Config file not found";
        case InvalidConfigFile:
            return "Code [2]: Invalid config file, it may be corrupted";
        case MemoryAllocationFailure:
            return "Code [3]: Failed to allocate the initial memory pool";
    }
}