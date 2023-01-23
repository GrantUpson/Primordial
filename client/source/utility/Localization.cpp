#include <fstream>
#include <filesystem>
#include "Localization.h"


bool Localization::Load(Languages language) {
    Localization::strings.clear();
    std::string filepath = std::filesystem::current_path().string() + "/Data/Languages/";

    switch(language) {
        case ENGLISH:
            RetrieveStrings(filepath + "english.lang");
            break;
        case CHINESE:
            RetrieveStrings(filepath + "chinese.lang");
            break;
        case RUSSIAN:
            RetrieveStrings(filepath + "russian.lang");
            break;
        case SPANISH:
            RetrieveStrings(filepath + "spanish.lang");
            break;
        case GERMAN:
            RetrieveStrings(filepath + "german.lang");
            break;
        case FRENCH:
            RetrieveStrings(filepath + "french.lang");
            break;
        case PORTUGUESE:
            RetrieveStrings(filepath + "portuguese.lang");
            break;
        case JAPANESE:
            RetrieveStrings(filepath + "japanese.lang");
            break;
        case ITALIAN:
            RetrieveStrings(filepath + "italian.lang");
            break;
        case KOREAN:
            RetrieveStrings(filepath + "korean.lang");
            break;
        case POLISH:
            RetrieveStrings(filepath + "polish.lang");
            break;
        default:
            return false;
    }

    return true;
}


std::string Localization::GetString(std::string id) {
    return Localization::strings[id];
}


void Localization::RetrieveStrings(const std::string& filename) {
    if(std::ifstream configurationFileStream {filename}; configurationFileStream) {
        for (std::string line{}; std::getline(configurationFileStream, line); ) {
            if (line.find('=') != std::string::npos) {
                std::istringstream iss {line};

                if(std::string key {}, value {}; std::getline(std::getline(iss, key, '=') >> std::ws, value)) {
                    Localization::strings[key] = value;
                }
            }
        }
    }
}


