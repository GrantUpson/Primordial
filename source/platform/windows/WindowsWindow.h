#ifndef INDARKESTNIGHT_WINDOWSWINDOW_H
#define INDARKESTNIGHT_WINDOWSWINDOW_H


#include "../../client/Window.h"

class WindowsWindow : Window{
public:
    WindowsWindow();

private:
    std::string title;
    uint32 width;
    uint32 height;
};


#endif
