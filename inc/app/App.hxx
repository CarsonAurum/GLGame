//
// Carson R - 1/10/2023
//

#ifndef TITANOFAIR_APP_HXX
#define TITANOFAIR_APP_HXX

#include "api/ecs/entities/Entity.hxx"
// NOTE: These will become less efficient with more items.
// Keep an eye on object counts for these containers.
#include <boost/container/flat_set.hpp>
#include <boost/container/flat_map.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/uuid/uuid.hpp>

namespace TitanOfAir
{
    class App
    {
    public:
        // Types
        enum ActionResult
        {
            // [App General Codes 00xx]
            APP_SUCCESS = 0000,
            // [Entity Codes 01xx]
            APP_ENTITY_PRESENT = 0100
        };

        // API
        App(App&) = delete;
        void operator =(const App&) = delete;
        static App* getInstance();

        // Public Constants
        static const char* NAME;
        static const char* APP_NAME;

        // ECS
        std::size_t getEntityCount();
        std::size_t getComponentCount();
        ActionResult addEntity(Entity*);
        ActionResult removeEntity(Entity*);
        ActionResult getStatusFor(Entity*);
        ActionResult addComponent(Component*);
        ActionResult removeComponent(Component*);
        ActionResult getStatusFor(Component*);

    protected:
        // Internal Usage Only
        App();
        ~App();
        bool hasEntity(Entity*);
        bool hasComponent(Component*);
        bool clearECS();
    private:
        // ECS
        boost::shared_mutex* eMutex;
        boost::container::flat_set<boost::uuids::uuid*>* entities;
        boost::shared_mutex* cMutex;
        boost::container::flat_set<boost::uuids::uuid*>* components;
        boost::shared_mutex* esMutex;
        boost::container::flat_map<boost::uuids::uuid*, ActionResult>* eStatus;
        boost::shared_mutex* csMutex;
        boost::container::flat_map<boost::uuids::uuid*, ActionResult>* cStatus;
    };
    const char* App::NAME = "Titan Of Air";
    const char* App::APP_NAME = "titan_of_air";
}

#endif //TITANOFAIR_APP_HXX
