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
        enum ActionResult
        {
            APP_SUCCESS = 0;
        };
    public:
        App(App&) = delete;
        void operator =(const App&) = delete;
        static App* getInstance();

        // ECS
        std::size_t getEntityCount();
        std::size_t getComponentCount();
        ActionResult addEntity(Entity* entity);
        ActionResult removeEntity(Entity* entity);
    protected:
        App();
        ~App();
    private:
        std::shared_mutex* eMutex;
        boost::container::stable_vector<boost::uuids::uuid*>* entities;
        std::shared_mutex* cMutex;
        boost::container::stable_vector<boost::uuids::uuid*>* components;
    };
}

#endif //TITANOFAIR_APP_HXX
