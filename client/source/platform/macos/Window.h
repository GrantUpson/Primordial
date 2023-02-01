#ifndef PRIMORDIAL_WINDOW_H
#define PRIMORDIAL_WINDOW_H


#include <string>
#include "utility/Utility.h"
#include "glad/glad.h"
#include "glfw3.h"


struct WindowData {
    std::string title;
    uint32 width;
    uint32 height;
    bool vSyncEnabled;
    bool windowedModeEnabled;

    explicit WindowData(std::string title = "Primordial", bool windowedModeEnabled = false, uint32 width = 1920, uint32 height = 1080, bool vSyncEnabled = true) :
            title(std::move(title)), windowedModeEnabled(windowedModeEnabled), width(width), height(height), vSyncEnabled(true) {};

};

class Window {
public:
    explicit Window(const WindowData* data);
    ~Window() = default;

    uint32 GetWidth() const;
    uint32 GetHeight() const;
    bool VSyncEnabled() const;
    bool WindowedModeEnabled() const;

    GLFWwindow* GetWindow();
    void Close();
private:
    std::string title;
    uint32 width;
    uint32 height;
    bool vSyncEnabled;
    bool windowedModeEnabled;
    GLFWwindow* window; //TODO Native windows window
};


#endif
