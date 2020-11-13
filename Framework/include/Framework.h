#pragma once
#include <memory>
#include "Window.h"
#include "IRenderer.h"
namespace  nano
{
    namespace framework
    {
        class Framework
        {
        public:
            void renderLoop();
            std::shared_ptr<Window> getWindow()
            {
                return globWindow;
            }
            void init(std::shared_ptr<IRenderer> renderer_);
        private:
            std::shared_ptr<Window> globWindow;
            std::shared_ptr<IRenderer> renderer;

        };


    }
}