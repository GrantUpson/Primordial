#include <filesystem>
#include <string>
#include "utility/settings.h"
#include "simple_ini/simple_ini.h"
#include "utility/localization.h"


Settings::Graphics Settings::graphics;
Settings::Audio Settings::audio;
Settings::Gameplay Settings::gameplay;


ClientStatus Settings::LoadSettings() {
    CSimpleIniA ini;
    ini.SetUnicode();

    std::string currentPath = std::filesystem::current_path().c_str();
    std::string filePath = currentPath + SETTINGS_FILEPATH;
    SI_Error rc = ini.LoadFile(filePath.c_str());

    if(rc < 0) {
        return InvalidSettingsFile;
    }

    graphics.resolutionWidth = std::stoi(ini.GetValue("Graphics", "ResolutionWidth", "640"));
    graphics.resolutionHeight = std::stoi(ini.GetValue("Graphics", "ResolutionHeight", "480"));
    graphics.windowedMode = ini.GetBoolValue("Graphics", "WindowedMode", "false");
    graphics.vSync = ini.GetBoolValue("Graphics", "VSync", "true");

    audio.masterVolume = std::stoi(ini.GetValue("Audio", "MasterVolume", "75"));
    audio.musicVolume = std::stoi(ini.GetValue("Audio", "MusicVolume", "50"));
    audio.effectsVolume = std::stoi(ini.GetValue("Audio", "EffectsVolume", "75"));
    audio.subtitles = ini.GetBoolValue("Audio", "Subtitles", "false");

    gameplay.firstPlay = ini.GetBoolValue("Gameplay", "FirstPlay", "true");
    gameplay.language = static_cast<Languages>(std::stoi(ini.GetValue("Gameplay", "Language", "0")));

    return Initialized;
}


bool Settings::SaveSettings() {
    CSimpleIniA ini;
    ini.SetUnicode();

    ini.SetValue("Graphics", "ResolutionWidth", std::to_string(graphics.resolutionWidth).c_str());
    ini.SetValue("Graphics", "ResolutionHeight", std::to_string(graphics.resolutionHeight).c_str());
    ini.SetValue("Graphics", "WindowedMode", std::to_string(graphics.windowedMode).c_str());
    ini.SetValue("Graphics", "VSync", std::to_string(graphics.vSync).c_str());

    ini.SetValue("Audio", "MasterVolume", std::to_string(audio.masterVolume).c_str());
    ini.SetValue("Audio", "MusicVolume", std::to_string(audio.musicVolume).c_str());
    ini.SetValue("Audio", "EffectsVolume", std::to_string(audio.effectsVolume).c_str());
    ini.SetValue("Audio", "Subtitles", std::to_string(audio.subtitles).c_str());

    ini.SetValue("Gameplay", "FirstPlay", std::to_string(gameplay.firstPlay).c_str());
    ini.SetValue("Gameplay", "Language", std::to_string(gameplay.language).c_str());

    std::string currentPath = std::filesystem::current_path().c_str();
    std::string filePath = currentPath + Settings::SETTINGS_FILEPATH;
    SI_Error rc = ini.SaveFile(filePath.c_str());

    return rc >= 0;
}