//
// Carson R - 1/10/2023
//

#ifndef TITANOFAIR_APP_HXX
#define TITANOFAIR_APP_HXX

#include <shared_mutex>
#include <boost/container/stable_vector.hpp>
#include <boost/uuid/uuid.hpp>
#include "api/ecs/entities/Entity.hxx"

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

        // ECS
        std::size_t getEntityCount();
        std::size_t getComponentCount();
        ActionResult addEntity(Entity* e);
        ActionResult removeEntity(Entity* e);
    protected:
        // Internal Usage Only
        App();
        ~App();
        bool hasEntity(Entity* e);
    private:
        bool searchForEntity(boost::uuids::uuid* id, int l, int h);

        std::shared_mutex* eMutex;
        boost::container::stable_vector<boost::uuids::uuid*>* entities;
        std::shared_mutex* cMutex;
        boost::container::stable_vector<boost::uuids::uuid*>* components;
    };
}

#endif //TITANOFAIR_APP_HXX
