#ifndef PRIMORDIAL_SETTINGS_H
#define PRIMORDIAL_SETTINGS_H


#include <unordered_map>

class Settings {
public:
    Settings() = default;
    ~Settings() = default;

    bool Load(const std::string& filename);
    std::unordered_map<std::string, std::string>& GetSettings();

private:
    std::unordered_map<std::string, std::string> settings {};
};


#endif
