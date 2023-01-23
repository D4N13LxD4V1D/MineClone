#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "../input/input.hpp"

class Window
{
public:
    Window(int width, int height, const char *title, bool fullscreen);
    ~Window();

    void swapBuffers();
    void update();

    bool shouldClose();
    void close();

    bool isFullScreen();
    void setFullScreen(bool fullscreen);

private:
    GLFWwindow *window;
};