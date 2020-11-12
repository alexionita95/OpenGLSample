#pragma once
#include <memory>
#include "Window.h"
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
            void init();
        private:
            std::shared_ptr<Window> globWindow;

        };


    }
}