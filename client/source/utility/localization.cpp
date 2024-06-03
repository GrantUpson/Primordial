#include <filesystem>
#include "utility/localization.h"


bool Localization::LoadLanguage(Languages language) {
    Localization::strings.clear();
    std::string filepath = std::filesystem::current_path().string() + "/data/languages/";

    /*
    switch(language) {
        case ENGLISH:
            Utility::LoadSettingsFile(filepath + "english.lang", strings);
            break;
        case CHINESE:
            Utility::LoadSettingsFile(filepath + "chinese.lang", strings);
            break;
        case RUSSIAN:
            Utility::LoadSettingsFile(filepath + "russian.lang", strings);
            break;
        case SPANISH:
            Utility::LoadSettingsFile(filepath + "spanish.lang", strings);
            break;
        case GERMAN:
            Utility::LoadSettingsFile(filepath + "german.lang", strings);
            break;
        case FRENCH:
            Utility::LoadSettingsFile(filepath + "french.lang", strings);
            break;
        case PORTUGUESE:
            Utility::LoadSettingsFile(filepath + "portuguese.lang", strings);
            break;
        case JAPANESE:
            Utility::LoadSettingsFile(filepath + "japanese.lang", strings);
            break;
        case ITALIAN:
            Utility::LoadSettingsFile(filepath + "italian.lang", strings);
            break;
        case KOREAN:
            Utility::LoadSettingsFile(filepath + "korean.lang", strings);
            break;
        case POLISH:
            Utility::LoadSettingsFile(filepath + "polish.lang", strings);
            break;
        default:
            return false;
    }

    */
    return true;
}


std::string Localization::GetString(const std::string& id) {
    return Localization::strings[id];
}


