#ifndef INDARKESTNIGHT_WINDOW_H
#define INDARKESTNIGHT_WINDOW_H


#include <string>
#include "Utility.h"
#include "glfw3.h"
#include "../../../libraries/glfw-3.3.7/include/GLFW/glfw3.h"


struct WindowData {
    std::string title;
    uint32 width;
    uint32 height;

    explicit WindowData(std::string title = "In Darkest Night", uint32 width = 1920, uint32 height = 1080) :
               title(std::move(title)), width(width), height(height) {}
};

class Window {
public:
    explicit Window(const WindowData* data);
    ~Window() = default;

    uint32 GetWidth() const;
    uint32 GetHeight() const;
    void Close();
private:
    std::string title;
    uint32 width;
    uint32 height;
    GLFWwindow* window;
};


#endif
