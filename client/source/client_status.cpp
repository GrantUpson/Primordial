#include "client_status.h"


std::string ClientStatusToString(ClientStatus status) {
    switch(status) {
        case Initialized:
            return "Code [0]: Client initialized successfully";
        case InvalidSettingsFile:
            return "Code [1]: Invalid settings file, it may be corrupted";
        case LanguageFileNotFound:
            return "Code [2]: Language file could not be found";
        case InvalidLanguageFile:
            return "Code [3]: Invalid language file, it may be corrupted";
    }
}