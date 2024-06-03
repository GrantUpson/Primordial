#include <filesystem>
#include "utility/localization.h"
#include "simple_ini/simple_ini.h"


std::unordered_map<std::string, std::string> Localization::strings;


ClientStatus Localization::LoadLanguage(Languages language) {
    strings.clear();
    std::string filepath = std::filesystem::current_path().string() + LANGUAGES_FILEPATH;

    switch(language) {
        case English:
            return LoadFile(filepath + "english.lang");
        case Chinese:
            return LoadFile(filepath + "chinese.lang");
        case Russian:
            return LoadFile(filepath + "russian.lang");
        case Spanish:
            return LoadFile(filepath + "spanish.lang");
        case German:
            return LoadFile(filepath + "german.lang");
        case French:
            return LoadFile(filepath + "french.lang");
        case Portuguese:
            return LoadFile(filepath + "portuguese.lang");
        case Japanese:
            return LoadFile(filepath + "japanese.lang");
        case Italian:
            return LoadFile(filepath + "italian.lang");
        case Korean:
            return LoadFile(filepath + "korean.lang");
        case Polish:
            return LoadFile(filepath + "polish.lang");
    }
}


ClientStatus Localization::LoadFile(const std::string& filepath) {
    CSimpleIniA ini;
    ini.SetUnicode();
    SI_Error rc = ini.LoadFile(filepath.c_str());

    if (rc < 0) {
        return LanguageFileNotFound;
    }

    CSimpleIniA::TNamesDepend sections;
    ini.GetAllSections(sections);

    for (auto& sectionIt : sections) {
        const char *section = sectionIt.pItem;

        CSimpleIniA::TNamesDepend keys;
        ini.GetAllKeys(section, keys);

        for (auto &keyIt: keys) {
            const char *key = keyIt.pItem;
            const char *value = ini.GetValue(section, key, "");
            strings[key] = value;
        }
    }

    return Initialized;
}


std::string Localization::GetString(const std::string& id) {
    return strings[id];
}


