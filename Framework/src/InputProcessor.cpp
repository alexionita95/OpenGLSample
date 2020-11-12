#include "Window.h"
#include "..\include\InputProcessor.h"

namespace nano {
    namespace framework {
        void InputProcessor::init(std::shared_ptr<Window> window_)
        {
            if (!initialized) {
                window = window_;
                glfwSetInputMode(window->GetGLFWWindow(), GLFW_STICKY_KEYS, GL_TRUE);
                subscribeToEvents();
                initialized = true;
            }
        }

        void InputProcessor::update()
        {
            if (initialized) {
                glfwPollEvents();
            }
        }

        void InputProcessor::OnClose(GLFWwindow * W)
        {
            get().OnCloseImpl(W);
        }

        void InputProcessor::OnCloseImpl(GLFWwindow * W)
        {
            for (auto& cb : closeCallbacks)
                cb(W);
        }

        void InputProcessor::OnResize(GLFWwindow * W, int width, int height)
        {
        }

        void InputProcessor::OnError(int error, const char * description)
        {
        }

        void InputProcessor::KeyCallback(GLFWwindow * W, int key, int scancode, int action, int mods)
        {
            get().KeyCallbackImpl(W, key, scancode, action, mods);
        }

        void InputProcessor::KeyCallbackImpl(GLFWwindow * W, int key, int scancode, int action, int mods)
        {
        }

        void InputProcessor::CursorMove(GLFWwindow * W, double posX, double posY)
        {
        }

        void InputProcessor::MouseClick(GLFWwindow * W, int button, int action, int mods)
        {
        }

        void InputProcessor::MouseScroll(GLFWwindow * W, double offsetX, double offsetY)
        {
        }

        void InputProcessor::subscribeToEvents()
        {
            glfwSetWindowCloseCallback(window->GetGLFWWindow(), InputProcessor::OnClose);
            glfwSetWindowSizeCallback(window->GetGLFWWindow(), InputProcessor::OnResize);
            glfwSetKeyCallback(window->GetGLFWWindow(), InputProcessor::KeyCallback);
            glfwSetMouseButtonCallback(window->GetGLFWWindow(), InputProcessor::MouseClick);
            glfwSetCursorPosCallback(window->GetGLFWWindow(), InputProcessor::CursorMove);
            glfwSetScrollCallback(window->GetGLFWWindow(), InputProcessor::MouseScroll);
        }

    }
}
