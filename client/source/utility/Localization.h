#ifndef PRIMORDIAL_LOCALIZATION_H
#define PRIMORDIAL_LOCALIZATION_H

#include <string>
#include <unordered_map>

enum Languages {
    ENGLISH = 0, CHINESE = 1, RUSSIAN = 2, SPANISH = 3, GERMAN = 4, FRENCH = 5,
    PORTUGUESE = 6, JAPANESE = 7, ITALIAN = 8, KOREAN = 9, POLISH = 10
};

class Localization {
public:
    Localization() = default;
    ~Localization() = default;

    static bool LoadLanguage(Languages language);
    static std::string GetString(const std::string& id);

private:
    inline static std::unordered_map<std::string, std::string> strings;
};


#endif
