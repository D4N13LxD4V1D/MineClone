#include "input/input.hpp"
#include "window/window.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    Window window(1280, 720, "My Minecraft Clone", false);

    while (window.shouldClose() == false)
    {
        window.update();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        if (Input::isKeyPressed(GLFW_KEY_F1))
        {
            bool isFullScreen = window.isFullScreen();
            window.setFullScreen(!isFullScreen);
        }
        if (Input::mousePosition.x > 50)
        {
            std::cout << "Mouse position: " << Input::mousePosition.x << ", " << Input::mousePosition.y << std::endl;
        }
        if (Input::isKeyPressed(GLFW_KEY_ESCAPE))
        {
            window.close();
        }

        window.swapBuffers();
    }

    return 0;
}