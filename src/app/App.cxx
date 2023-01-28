//
// Carson R - 1/23/2023
//

// Dependencies
#include <boost/thread/shared_mutex.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/unordered/unordered_map.hpp>
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
        sharedInstance->eMutex->lock();
        sharedInstance->cMutex->lock();
    }
    return sharedInstance;
}

// Accessors

std::size_t App::eCount()
{
    return this->entities->size();
}

std::size_t App::cCount()
{
    return this->components->size();
}


// Construction & Destruction
App::App()
{
    this->eMutex = new boost::shared_mutex{};
    this->entities = new EntityContainer{};
    this->cMutex = new boost::shared_mutex{};
    this->components = new ComponentContainer{};
}

void App::init()
{
    this->eMutex->unlock();
    this->cMutex->unlock();
}

App::~App()
{
    eMutex->lock();
    assert(this->entities->empty());
    delete this->entities;
    eMutex->unlock();
    delete eMutex;

    cMutex->lock();
    assert(this->components->empty());
    delete this->components;
    cMutex->unlock();
    delete cMutex;
}


App::Response App::add(Entity *e)
{
    if (this->entities->find(e->getID()) != this->entities->end())
    {
        return { Response::APP_ENTY_PRESENT }
    }



    return {Response::APP_SUCCESS};
}

App::Response App::remove(Entity *e)
{

    return {Response::APP_SUCCESS};
}

App::Response App::getStatusFor(Entity *e)
{
    return {Response::APP_SUCCESS};
}

App::Response App::add(Component *c)
{
    return {Response::APP_SUCCESS};
}

App::Response App::remove(Component *c)
{
    return {Response::APP_SUCCESS};
}

App::Response App::getStatusFor(Component *c)
{
    return {Response::APP_SUCCESS};
}

bool App::hasEntity(Entity *e)
{
    return false;
}

bool App::hasComponent(Component *c)
{
    return false;
}

bool App::clearECS()
{
    return false;
}

// App Response

App::Response::Response()
{
    this->cause = APP_ENTY_OK;
}

App::Response::Response(ActionResult cause)
{
    this->cause = cause;
}

const char *App::Response::what() const noexcept
{
    switch (this->cause)
    {
        case ActionResult::APP_SUCCESS: return "App Success";
        case ActionResult::APP_FAILURE: return "App Failure";

        case ActionResult::APP_ENTY_OP_SUCCESS: return "Entity Operation Success";
        case ActionResult::APP_ENTY_OP_ERROR: return "Entity Operation Failure";
        case ActionResult::APP_ENTY_PRESENT: return "Entity Present";
        case ActionResult::APP_ENTY_NOT_PRESENT: return "Entity Not Present";

        case ActionResult::APP_CMPT_OP_SUCCESS: return "Component Operation Success";
        case ActionResult::APP_CMPT_OP_ERROR: return "Component Operation Failure";
        case ActionResult::APP_CMPT_PRESENT: return "Component Present";
        case ActionResult::APP_CMPT_NOT_PRESENT: return "Component Not Present";

        default: return "";

    }
}

unsigned short App::Response::getCode()
{
    return this->cause;
}

bool App::Response::is(App::Response::ActionResult res)
{
    return this->getCode() == res;
}

