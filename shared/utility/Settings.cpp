#include <string>
#include "Settings.h"
#include "Utility.h"


bool Settings::Load(const std::string &filename) {
    return Utility::LoadSettingsFile(filename, settings);
}


std::string Settings::GetSetting(const std::string& key) {
    return settings[key];
}


void Settings::Save(const std::string &key, const std::string& value) {
    settings[key] = value;
}


bool Settings::SaveToFile(const std::string& filename) {
    return Utility::SaveSettingsFile(filename, settings);
}


