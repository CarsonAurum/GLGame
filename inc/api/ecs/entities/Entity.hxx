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
         * The default constructor creates the id.
         * @note This constructor should be called from all implementing classes.
         */
        Entity();
        /**
         * The copy constructor for copying this object. Explicitly disallowed.
         */
        Entity(const Entity& copy) = delete;
        /**
         * The move constructor for relocating this object. Explicitly disallowed.
         */
        Entity(Entity&& move) = delete;
        /**
         * The copy assignment operator for relocating this object. Explicitly disallowed.
         */
        void operator =(const Entity&) = delete;
        ~Entity();

        boost::uuids::uuid* getID();
    protected:
        boost::uuids::uuid* id;
    };
}

#endif //TITANOFAIR_ENTITY_HXX
