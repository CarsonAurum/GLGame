//
// Carson R - 1/23/2023
//

// Dependencies
#include <boost/thread/shared_mutex.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/uuid/uuid.hpp>
// NOTE: These will become less efficient with more items.
// Keep an eye on object counts for these containers.
#include <boost/container/flat_map.hpp>
#include <boost/container/flat_set.hpp>
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
        sharedInstance->esMutex->lock();
        sharedInstance->csMutex->lock();
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
    this->entities = new boost::container::flat_set<const boost::uuids::uuid *>{};
    this->eMutex = new boost::shared_mutex{};
    this->components = new boost::container::flat_set<const boost::uuids::uuid *>{};
    this->cMutex = new boost::shared_mutex{};
    this->eStatus = new boost::container::flat_map<const boost::uuids::uuid *, Response>{};
    this->esMutex = new boost::shared_mutex{};
    this->cStatus = new boost::container::flat_map<const boost::uuids::uuid *, Response>{};
    this->csMutex = new boost::shared_mutex{};
}

void App::init()
{
    this->eMutex->unlock();
    this->cMutex->unlock();
    this->esMutex->unlock();
    this->csMutex->unlock();
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

    esMutex->lock();
    assert(this->eStatus->empty());
    delete this->eStatus;
    esMutex->unlock();
    delete esMutex;

    csMutex->lock();
    assert(this->cStatus->empty());
    delete this->cStatus;
    csMutex->unlock();
    delete csMutex;
}


App::Response App::add(Entity *e)
{
    this->eMutex->lock_upgrade();
    if (this->entities->contains(e->getID()))
    {
        this->eMutex->unlock();
        return {Response::APP_ENTY_PRESENT};
    }
    this->eMutex->unlock_upgrade_and_lock();
    auto res1 = this->entities->insert(e->getID());
    this->eMutex->unlock();
    if (res1.second)
    {
        this->esMutex->lock();
        this->eStatus->insert(std::pair<const boost::uuids::uuid*,
                              Response::ActionResult>(
                        e->getID(), {Response::APP_ENTY_OK}));
        this->esMutex->unlock();
        return {Response::APP_SUCCESS};
    }
    else
    {
        return { Response::APP_ENTY_OP_SUCCESS };
    }
}

App::Response App::remove(Entity *e)
{
    this->eMutex->lock_upgrade();
    if (this->entities->contains())

    this->eMutex->unlock();
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

