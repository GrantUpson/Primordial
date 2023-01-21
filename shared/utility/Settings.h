#ifndef PRIMORDIAL_CONFIGURATION_H
#define PRIMORDIAL_CONFIGURATION_H


#include <unordered_map>

class Configuration {
public:
    Configuration() = default;
    ~Configuration() = default;

    bool Load(const std::string& filename);
    std::unordered_map<std::string, std::string>& GetSettings();
private:
    std::unordered_map<std::string, std::string> settings {};
};


#endif
