#ifndef PRIMORDIAL_WINDOW_H
#define PRIMORDIAL_WINDOW_H


#include "glad/glad.h"
#include <string>
#include <utility>
#include "types.h"
#include "glfw3.h"

struct WindowData {
    std::string title;
    uint32 width;
    uint32 height;
    bool vSyncEnabled;
    bool windowedModeEnabled;

    explicit WindowData(std::string title = "Primordial", bool windowedModeEnabled = false, uint32 width = 640, uint32 height = 360, bool vSyncEnabled = true) :
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

    void SetResolution(uint32 width, uint32 height);

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
