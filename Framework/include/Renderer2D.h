#pragma once
#include <memory>
#include "IRenderer.h"
namespace  nano
{
	namespace framework
	{
		class Renderer2D : public IRenderer
		{
		public:
			void Render() override;

		};


	}
}