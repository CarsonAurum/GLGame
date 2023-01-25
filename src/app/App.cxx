//
// Carson R - 1/23/2023
//

#include "app/App.hxx"
#include <shared_mutex>
#include <boost/container/stable_vector.hpp>
#include <boost/uuid/uuid.hpp>

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
    this->entities = new boost::container::stable_vector<
            boost::uuids::uuid*>{20};
    this->eMutex = new std::shared_mutex{};
    this->components = new boost::container::stable_vector<
            boost::uuids::uuid*> {20};
    this->cMutex = new std::shared_mutex{};
}

App::~App()
{
    // Ensure this is ONLY done after all the components/entities have been
    // freed.
    assert(this->entities->empty());
    assert(this->components->empty());
    delete this->entities;
    delete this->components;
}

App::ActionResult App::addEntity (Entity* entity)
{
    if( std::binary_search(this->entities->begin(), this->entities->end(), entity->getID()))
    {
        return APP_ENTITY_PRESENT;
    }
    this->entities->push_back(entity->getID());
    std::sort(this->entities->begin(), this->entities->end());
    return APP_SUCCESS;
}

App::ActionResult App::removeEntity (Entity* entity)
{
    return APP_SUCCESS;
}
