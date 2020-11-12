#include <Framework.h>
#include <InputProcessor.h>
#include  <memory>
int main( void )
{
    std::shared_ptr<nano::framework::Framework> framework = std::make_shared<nano::framework::Framework>();
    framework->init();
    nano::framework::InputProcessor::get().init(framework->getWindow());
    framework->renderLoop();
    return 0;
}
