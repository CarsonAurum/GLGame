//
// Carson R - 1/17/2023
//

#ifndef TITANOFAIR_ENTITY_HXX
#define TITANOFAIR_ENTITY_HXX

#include <uuid_v4.h>
#include <endianness.h>
#include "API_ERRORS.hxx"
#include "Component.hxx"

namespace TitanOfAir
{
    /**
     * An abstract superclass representing an entity in the TitanOfAir ECS
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
         * The copy constructor for copying this object.
         * @note This must be implemented by all subclasses.
         * @param copy The component whose data should be copied, leaving the
         * given entity unchanged.
         */
        Entity(const Entity& copy) = delete;
        /**
         * The move constructor for relocating this object.
         * @note This must be implemented by all subclasses.
         * @param move The component whose data should be moved to the target
         * destination.
         * @post This constructor should clear the parameter's values by calling
         * its destructor.
         */
        Entity(Entity&& move) = delete;
        virtual ~Entity() = delete;
    private:
        UUIDv4::UUID id;
    };
}

#endif //TITANOFAIR_ENTITY_HXX
