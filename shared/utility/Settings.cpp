#include <fstream>
#include <string>
#include <sstream>
#include "Settings.h"

bool Settings::Load(const std::string& filename) {
    if(std::ifstream configurationFileStream {filename}; configurationFileStream) {
        for (std::string line{}; std::getline(configurationFileStream, line); ) {
            if (line.find('=') != std::string::npos) {
                std::istringstream iss {line};

                if(std::string key {}, value {}; std::getline(std::getline(iss, key, '=') >> std::ws, value)) {
                    settings[key] = value;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}


std::unordered_map<std::string, std::string>& Settings::GetSettings() {
    return settings;
}
