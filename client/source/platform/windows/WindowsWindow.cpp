#include <iostream>
#include "Window.h"
#include "utility/Logger.h"


static void ErrorCallback(int error, const char* description) {
    Logger::Log("Client - Error " + std::to_string(error) + ": " + std::string(description));
}

Window::Window(const WindowData* data) {
    title = data->title;
    width = data->width;
    height = data->height;
    vSyncEnabled = data->vSyncEnabled;
    windowedModeEnabled = data->windowedModeEnabled;

    glfwSetErrorCallback(ErrorCallback);

    if(!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_AUTO_ICONIFY, GL_FALSE);

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    window = glfwCreateWindow(mode->width, mode->height, title.c_str(), monitor, nullptr);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if(!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    if(windowedModeEnabled) {
        glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }


    glViewport(0, 0, width, height);
}

void Window::Close() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

uint32 Window::GetHeight() const {
    return height;
}

uint32 Window::GetWidth() const {
    return width;
}

bool Window::VSyncEnabled() const {
    return vSyncEnabled;
}

bool Window::WindowedModeEnabled() const {
    return windowedModeEnabled;
}

void Window::SetResolution(uint32 newWidth, uint32 newHeight) {
    this->width = newWidth;
    this->height = newHeight;
}

GLFWwindow* Window::GetWindow() {
    return window;
}







