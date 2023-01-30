//
// Carson R - 1/23/23
//

#ifndef TITANOFAIR_COMPONENT_HXX
#define TITANOFAIR_COMPONENT_HXX

// Libs
#include "boost/uuid/uuid.hpp"
#include "api/ecs/core/ECS.hxx"
#include "boost/thread/shared_mutex.hpp"

namespace TitanOfAir::ECS
{
    /**
     * An abstract superclass representing a component in the TitanOfAir ECS system.
     * Entities should be placed dynamically on the heap, so their lifetime can be managed by the
     * game's core ecs framework.
     */
    class Component
    {
    public:
        /**
         * The default constructor creates the id for this component.
         */
        Component();

        /**
         * The copy constructor for duplicating the given object.
         */
        Component(const Component &);

        /**
         * The move constructor for relocating the given object.
         */
        Component(const Component &&);

        /**
         * The copy assignment operator for duplicating this object.
         */
        void operator=(const Component &);

        /**
         * The move assignment operator for relocating this object.
         */
        void operator=(const Component &&);

        /**
         * The destructor for this object.
         */
        ~Component();

        /**
         * Access a pointer to the ID associated with this object.
         * @return A constant pointer to the UUID for this object.
         */
        [[nodiscard]] const boost::uuids::uuid *getID();

    protected:
        const boost::uuids::uuid id;
        Response *ret;
        boost::shared_mutex *mut;
        boost::unordered::unordered_set<const boost::uuids::uuid *> *installed;
    };
}

#endif //TITANOFAIR_COMPONENT_HXX
