#pragma once
#include <glm/vec2.hpp>
#include <string>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "memory"
#include <functional>
#include <vector>
namespace nano
{
    namespace framework
    {

        class InputProcessor
        {

        public:
            typedef std::function<void(GLFWwindow *W)> CloseCallback;
            static InputProcessor& get()
            {
                static InputProcessor instance;
                return instance;
            }
            void init(std::shared_ptr<Window> window_);
            void subscribeCloseToEvent(CloseCallback cb)
            {
                closeCallbacks.push_back(cb);
            }
            void update();

            bool isKeyPressed(int keyId) const
            {
                return glfwGetKey(window->GetGLFWWindow(), keyId) == GLFW_PRESS;
            }
        private:

            static void OnClose(GLFWwindow *W);
            void OnCloseImpl(GLFWwindow *W);
            static void OnResize(GLFWwindow *W, int width, int height);
            static void OnError(int error, const char* description);

            // KeyBoard
            static void KeyCallback(GLFWwindow *W, int key, int scancode, int action, int mods);
            void KeyCallbackImpl(GLFWwindow *W, int key, int scancode, int action, int mods);

            // Mouse
            static void CursorMove(GLFWwindow *W, double posX, double posY);
            static void MouseClick(GLFWwindow *W, int button, int action, int mods);
            static void MouseScroll(GLFWwindow *W, double offsetX, double offsetY);


            void subscribeToEvents();
            InputProcessor()
                :window(nullptr)
                , initialized(false)
            {

            }
            std::shared_ptr<Window> window;
            std::vector<CloseCallback> closeCallbacks;
            bool initialized;

        };
    }
}
