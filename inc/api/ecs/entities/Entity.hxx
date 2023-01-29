//
// Carson R - 1/17/2023
//

#ifndef TITANOFAIR_ENTITY_HXX
#define TITANOFAIR_ENTITY_HXX

// Libs
#include "boost/uuid/uuid.hpp"
// Local
#include "api/ecs/components/Component.hxx"

namespace TitanOfAir
{
    /**
     * An abstract superclass representing an entities in the TitanOfAir ecs
     * system.
     */
    class Entity
    {
    public:
        /**
         * The default constructor creates the id and registers this entity with the ECS system
         * manager.
         *
         * @throws TitanOfAir::Exception If the entity cannot be added to the global ECS system.
         */
        Entity();

        /**
         * The copy constructor for copying this object. Explicitly disallowed.
         */
        Entity(const Entity &) = delete;

        /**
         * The move constructor for relocating this object. Explicitly disallowed.
         */
        Entity(Entity &&) = delete;

        /**
         * The copy assignment operator for relocating this object. Explicitly disallowed.
         */
        void operator=(const Entity &) = delete;

        /**
         * The destructor for this object will remove itself from the shared ECS system manager
         * before releasing its resources.
         */
        ~Entity();

        /**
         * Access a pointer to the ID associated with this object.
         * @return A constant pointer to the UUID for this object.
         */
        const boost::uuids::uuid* getID() const;

    protected:
        const boost::uuids::uuid id;
    };
}

#endif //TITANOFAIR_ENTITY_HXX
