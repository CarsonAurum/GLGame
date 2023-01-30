//
// Carson R - 1/30/2023
//

#ifndef TITANOFAIR_ECSYSTEM_HXX
#define TITANOFAIR_ECSYSTEM_HXX

#include "boost/tuple/tuple.hpp"
#include "boost/thread/shared_mutex.hpp"
#include "boost/unordered/unordered_map.hpp"
#include "boost/uuid/uuid.hpp"

#include "api/ecs/components/Component.hxx"
#include "api/ecs/entities/Entity.hxx"
#include "api/ecs/core/Response.hxx"
#include "api/ecs/core/ECS.hxx"

namespace TitanOfAir::ECS
{
    class ECSystem
    {
    public:
        ECSystem();
        ECSystem(ECSystem&);
        void operator =(const ECSystem&);
        ~ECSystem();

        std::size_t entityCount() const;
        std::size_t componentCount() const;

        Response add(Entity*, Response*);
        Response remove(Entity*);
        bool has(Entity*) const;
        const Response* getStatus(Entity*) const;
        Response add(Component*, Response*);
        Response remove(Component*);
        bool has(Component*) const;
        const Response* getStatus(Component*) const;
        std::size_t clear();
    private:
        boost::shared_mutex* eMutex;
        EntityContainer* entities;
        boost::shared_mutex* cMutex;
        ComponentContainer* components;
    };
}

#endif //TITANOFAIR_ECSYSTEM_HXX
