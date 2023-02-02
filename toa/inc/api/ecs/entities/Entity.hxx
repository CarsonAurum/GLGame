//
// Carson R - 1/17/2023
//

#ifndef TITANOFAIR_ENTITY_HXX
#define TITANOFAIR_ENTITY_HXX

// Libs
#include <boost/unordered/unordered_set.hpp>
// Local
#include "api/ecs/core/ECS.hxx"

namespace TitanOfAir::ECS
{
    class Entity
    {
    public:
        Entity();

        Entity(const Entity& copy) = delete;

        Entity& operator=(const Entity& lhs) = delete;

        Entity(Entity&& move) noexcept;

        Entity& operator=(Entity&& lhs) noexcept;

        ~Entity();

        [[nodiscard]] std::string getID() const;

        void add(Component* c);

        void remove(Component* c);

    protected:
       ECData* data;
    private:
        friend ECSystem;
    };
}

#endif //TITANOFAIR_ENTITY_HXX
