#ifndef INDARKESTNIGHT_WINDOW_H
#define INDARKESTNIGHT_WINDOW_H

#include <string>
#include "../utility.h"

struct WindowData {
    std::string title;
    uint32 width;
    uint32 height;
};

class Window {
public:
    Window(const WindowData& data);
    virtual ~Window() = default;

    virtual uint32 GetWidth() const = 0;
    virtual uint32 GetHeight() const = 0;

    static Window* Create(const WindowData& data);
};


#endif
