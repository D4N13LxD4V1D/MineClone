#include "input.hpp"

Input::Input()
{
    for (int i = 0; i < 1024; i++)
    {
        keys[i] = false;
    }
}

Input::~Input()
{
}

void Input::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
        {
            keys[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            keys[key] = false;
        }
    }
}

bool Input::isKeyPressed(int key)
{
    if (key >= 0 && key < 1024)
    {
        return keys[key];
    }
    return false;
}

void Input::mousePositionCallback(GLFWwindow *window, double xpos, double ypos)
{
    mousePosition.x = xpos;
    mousePosition.y = ypos;
}