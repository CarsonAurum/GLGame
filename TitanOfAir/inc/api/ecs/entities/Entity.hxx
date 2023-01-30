//
// Carson R - 1/17/2023
//

#ifndef TITANOFAIR_ENTITY_HXX
#define TITANOFAIR_ENTITY_HXX

// Libs
#include <boost/uuid/uuid.hpp>
#include <boost/unordered/unordered_set.hpp>
// Local
#include "api/ecs/core/ECS.hxx"
#include "api/ecs/components/Component.hxx"
#include "boost/thread/shared_mutex.hpp"

namespace TitanOfAir::ECS
{
    /**
     * An abstract superclass representing an entities in the TitanOfAir ecs system.
     *
     * Entities should be placed dynamically on the heap, so their lifetime can be managed by the game's core
     * ecs framework.
     */
    class Entity
    {
    public:
        /**
         * The default constructor creates the id and initializes internal mechanisms.
         */
        Entity();

        /**
         * The copy constructor for copying this object.
         */
        Entity(const Entity &);

        /**
         * The move constructor for relocating this object.
         */
        Entity(const Entity &&);

        /**
         * The copy assignment operator for duplicating this entity.
         */
        void operator=(const Entity &);

        /**
         * The move assignment operator for relocating this entity.
         */
        void operator=(const Entity&&);

        /**
         * The destructor for this object will remove itself from the shared ECS system manager
         * before releasing its resources.
         */
        ~Entity();

        /**
         * Access a pointer to the ID associated with this object.
         * @return A constant pointer to the UUID for this object.
         */
         [[nodiscard]] const boost::uuids::uuid* getID() const;

         void add(Component*);

    protected:
        const boost::uuids::uuid* id;
        Response* ret;
        boost::shared_mutex*  mut;
        boost::unordered::unordered_set<const boost::uuids::uuid*>* installed;
    };
}

#endif //TITANOFAIR_ENTITY_HXX
