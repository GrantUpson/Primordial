#ifndef PRIMORDIAL_LOCALIZATION_H
#define PRIMORDIAL_LOCALIZATION_H

#include <string>
#include <unordered_map>
#include "client_status.h"


enum Languages {
    English = 0, Chinese = 1, Russian = 2, Spanish = 3, German = 4, French = 5,
    Portuguese = 6, Japanese = 7, Italian = 8, Korean = 9, Polish = 10
};


class Localization {
public:
    static constexpr const char* LANGUAGES_FILEPATH = "/data/languages/";

    static ClientStatus LoadLanguage(Languages language);
    static std::string GetString(const std::string& id);

    Localization() = delete;
    ~Localization() = delete;

private:
    static std::unordered_map<std::string, std::string> strings;
    static ClientStatus LoadFile(const std::string& filepath);
};


#endif
