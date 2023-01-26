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
    this->eStatus = new boost::container::flat_map<const boost::uuids::uuid *, ActionResult>{};
    this->esMutex = new boost::shared_mutex{};
    this->cStatus = new boost::container::flat_map<const boost::uuids::uuid *, ActionResult>{};
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


App::ActionResult App::add(Entity *e)
{
    this->eMutex->lock_upgrade();
    if (this->entities->contains(e->getID()))
    {
        this->eMutex->unlock();
        return APP_ENTY_PRESENT;
    }
    this->eMutex->unlock_upgrade_and_lock();
    auto res1 = this->entities->insert(e->getID());
    this->eMutex->unlock();
    if (res1.second)
    {
        this->esMutex->lock();
        this->eStatus->insert(boost::tuple<const boost::uuids::uuid *, bool>{e->getID(), false});
        this->esMutex->unlock();
        return APP_ENTY_OP_SUCCESS;
    }
    else
    {
        return APP_ENTY_OP_ERROR;
    }
}

App::ActionResult App::remove(Entity *e)
{
    this->eMutex->lock();

    this->eMutex->unlock();
    return APP_SUCCESS;
}

App::ActionResult App::getStatusFor(Entity *e)
{
    return APP_SUCCESS;
}

App::ActionResult App::add(Component *c)
{
    return APP_SUCCESS;
}

App::ActionResult App::remove(Component *c)
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

