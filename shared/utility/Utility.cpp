#include <fstream>
#include <sstream>
#include "Utility.h"


bool Utility::LoadSettingsFile(const std::string& filename, std::unordered_map<std::string, std::string> &map) {
    if(std::ifstream configurationFileStream {filename}; configurationFileStream) {
        for (std::string line{}; std::getline(configurationFileStream, line); ) {
            std::istringstream iss {line};

            if(std::string key {}, value {}; std::getline(std::getline(iss, key, '=') >> std::ws, value)) {
                map[key] = value;
            }
        }
        return true;
    } else {
        return false;
    }
}


bool Utility::SaveSettingsFile(const std::string& filename, std::unordered_map<std::string, std::string> &map) {
    return true;
}

