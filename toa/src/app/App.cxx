//
// Carson R - 1/23/2023
//

// Local Includes
#include "app/App.hxx"

using namespace TitanOfAir;

// Singleton

App *sharedInstance = nullptr;

App *App::shared()
{
    if (sharedInstance == nullptr)
    {
        sharedInstance = new App();
    }
    return sharedInstance;
}
// Construction & Destruction
App::App()
{}

bool App::init()
{
    return true;
}

App::~App()
{}

