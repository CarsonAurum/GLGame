//
// Carson R - 1/23/2023
//

#include "app/App.hxx"
#include <boost/thread/shared_mutex.hpp>
#include <boost/uuid/uuid.hpp>
// NOTE: These will become less efficient with more items.
// Keep an eye on object counts for these containers.
#include <boost/container/flat_map.hpp>
#include <boost/container/flat_set.hpp>

using namespace TitanOfAir;

// Singleton

App* sharedInstance = nullptr;

App* App::getInstance()
{
    if (sharedInstance == nullptr)
        sharedInstance = new App();
    return sharedInstance;
}

// Accessors

std::size_t App::getEntityCount ()
{
    return this->entities->size();
}

std::size_t App::getComponentCount ()
{
    return this->components->size();
}


// Construction & Destruction
App::App()
{
    this->entities = new boost::container::flat_set<boost::uuids::uuid*>{};
    this->eMutex = new boost::shared_mutex{};
    this->components = new boost::container::flat_set<boost::uuids::uuid*> {};
    this->cMutex = new boost::shared_mutex{};
    this->eStatus = new boost::container::flat_map<
            boost::uuids::uuid*, ActionResult>{};
    this->esMutex = new boost::shared_mutex{};
    this->cStatus = new boost::container::flat_map<
            boost::uuids::uuid*, ActionResult>{};
    this->csMutex = new boost::shared_mutex{};
}

App::~App()
{
    // TODO: Memory Cleanup
}

App::ActionResult App::addEntity (Entity* e)
{
    this -> eMutex -> lock();



    this -> eMutex -> unlock();
    return APP_SUCCESS;
}

App::ActionResult App::removeEntity (Entity* e)
{
    this -> eMutex -> lock();
    return APP_SUCCESS;
}

App::ActionResult App::getStatusFor (Entity* e)
{
    return APP_SUCCESS;
}

App::ActionResult App::addComponent (Component* c)
{
    return APP_SUCCESS;
}

App::ActionResult App::removeComponent (Component* c)
{
    return APP_SUCCESS;
}

App::ActionResult App::getStatusFor (Component* c)
{
    return APP_SUCCESS;
}

bool App::hasEntity (Entity* e)
{
    return false;
}

bool App::hasComponent (Component* c)
{
    return false;
}

bool App::clearECS ()
{
    return false;
}

