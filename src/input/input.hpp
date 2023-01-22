#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

struct MousePosition
{
    int x;
    int y;
};

class Input
{
public:
    Input();
    ~Input();

    static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
    static bool isKeyPressed(int key);

    static MousePosition mousePosition;
    static void mousePositionCallback(GLFWwindow *window, double xpos, double ypos);

private:
    static bool keys[1024];
};