#pragma once
#include <memory>
#include "Window.h"
namespace  nano
{
    namespace framework
    {
        class IRenderer
        {
        public:
            virtual void Render() = 0;

        };


    }
}