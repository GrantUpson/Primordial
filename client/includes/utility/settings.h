#ifndef PRIMORDIAL_SETTINGS_H
#define PRIMORDIAL_SETTINGS_H

#include "types.h"
#include "localization.h"
#include "client_status.h"


class Settings {
public:
    static constexpr const char* SETTINGS_FILEPATH = "/data/settings.config";

    struct Graphics {
        uint32 resolutionWidth;
        uint32 resolutionHeight;
        bool windowedMode;
        bool vSync;
    };

    struct Audio {
        int masterVolume;
        int musicVolume;
        int effectsVolume;
        bool subtitles;
    };

    struct Gameplay {
        bool firstPlay;
        Languages language;
    };

    static ClientStatus LoadSettings();
    static bool SaveSettings();

    static Graphics graphics;
    static Audio audio;
    static Gameplay gameplay;


    Settings() = delete;
    ~Settings() = delete;
    Settings(const Settings&) = delete;
    Settings& operator=(const Settings&) = delete;
};


#endif
