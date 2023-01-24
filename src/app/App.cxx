//
// Carson R - 1/23/2023
//

#include <app/App.hxx>

using namespace TitanOfAir;

App* sharedInstance = nullptr;

App* App::getInstance()
{
    if (sharedInstance == nullptr)
        sharedInstance = new App();
    return sharedInstance;
}

App::App()
{

}
