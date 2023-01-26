//
// Carson R - 1/23/2023
//

// Dependencies
#include <boost/thread/shared_mutex.hpp>
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

std::size_t App::getEntityCount()
{
    return this->entities->size();
}

std::size_t App::getComponentCount()
{
    return this->components->size();
}


// Construction & Destruction
App::App()
{
    this->entities = new boost::container::flat_set<boost::uuids::uuid *>{};
    this->eMutex = new boost::shared_mutex{};
    this->components = new boost::container::flat_set<boost::uuids::uuid *>{};
    this->cMutex = new boost::shared_mutex{};
    this->eStatus = new boost::container::flat_map<
            boost::uuids::uuid *, ActionResult>{};
    this->esMutex = new boost::shared_mutex{};
    this->cStatus = new boost::container::flat_map<
            boost::uuids::uuid *, ActionResult>{};
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


App::ActionResult App::addEntity(Entity *e)
{
    this->eMutex->lock();

    if (this->entities->contains(e->getID()))
    {
        this->eMutex->unlock();
        return APP_ENTY_PRESENT;
    }
    auto res = this->entities->insert(e->getID());
    if (res.second)
    {
        this->eMutex->unlock();
        return APP_ENTY_OP_SUCCESS;
    }
    else
    {
        this->eMutex->unlock();
        return APP_ENTY_OP_ERROR;
    }
}

App::ActionResult App::removeEntity(Entity *e)
{
    this->eMutex->lock();

    this->eMutex->unlock();
    return APP_SUCCESS;
}

App::ActionResult App::getStatusFor(Entity *e)
{
    return APP_SUCCESS;
}

App::ActionResult App::addComponent(Component *c)
{
    return APP_SUCCESS;
}

App::ActionResult App::removeComponent(Component *c)
{
    return APP_SUCCESS;
}

App::ActionResult App::getStatusFor(Component *c)
{
    return APP_SUCCESS;
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

