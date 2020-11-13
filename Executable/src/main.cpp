#include <Framework.h>
#include <InputProcessor.h>
#include <IRenderer.h>
#include <Renderer2D.h>
#include  <memory>
int main( void )
{
    std::shared_ptr<nano::framework::Framework> framework = std::make_shared<nano::framework::Framework>();
    std::shared_ptr<nano::framework::IRenderer> renderer = std::make_shared < nano::framework::Renderer2D>();
    framework->init(renderer);
    nano::framework::InputProcessor::get().init(framework->getWindow());
    framework->renderLoop();
    return 0;
}
 