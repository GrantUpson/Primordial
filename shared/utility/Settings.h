#ifndef PRIMORDIAL_SETTINGS_H
#define PRIMORDIAL_SETTINGS_H


#include <unordered_map>

class Settings {
public:
    Settings() = default;
    ~Settings() = default;

    static bool Load(const std::string& filename);
    static std::string GetSetting(const std::string& key);
    static void Save(const std::string& key, const std::string& value);
    static bool SaveToFile(const std::string& filename);

private:
    inline static std::unordered_map<std::string, std::string> settings {};
};


#endif
