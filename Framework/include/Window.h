#pragma once
#include <glm/vec2.hpp>
#include <string>
#include <GLFW/glfw3.h>
namespace nano
{
    namespace framework
    {
        class WindowProperties
        {
        public:
            std::string name;
            glm::ivec2 resolution;
            glm::ivec2 position;
            glm::ivec2 cursorPos;
            float aspectRatio;
            bool resizable;
            bool visible;
            bool fullScreen;
            bool centered;
            bool hideOnClose;
            bool vSync;

            WindowProperties()
            {
                name = "WindowName";
                resolution = glm::ivec2(1280, 720);
                aspectRatio = resolution.x / resolution.y;
                cursorPos = resolution / 2;
                position = glm::ivec2(0);
                resizable = true;
                centered = true;
                fullScreen = false;
                visible = true;
                hideOnClose = false;
                vSync = true;
            }

        };

        class Window
        {
        public:
            Window(WindowProperties props);
            ~Window();
            GLFWwindow* GetGLFWWindow() const
            {
                return window;
            }
            void setGLContext();
            bool shouldClose() const
            {
                return glfwWindowShouldClose(window) != 0;
            }

        protected:
            void init();
            WindowProperties properties;
            GLFWwindow* window;
            
        };
    }
}
