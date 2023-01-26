//
// Carson R - 1/23/23
//

#ifndef TITANOFAIR_COMPONENT_HXX
#define TITANOFAIR_COMPONENT_HXX

// Libs
#include "boost/uuid/uuid.hpp"

namespace TitanOfAir
{
    /**
     * An abstract superclass representing a component in the TitanOfAir ecs
     * system.
     */
    class Component
    {
    public:
        /**
         * The default constructor creates the id.
         * @note This constructor should be called from all implementing classes.
         */
        Component();

        /**
         * The copy constructor for copying this object. Explicitly disallowed.
         */
        Component(const Component &) = delete;

        /**
         * The move constructor for relocating this object. Explicitly disallowed.
         */
        Component(Component &&) = delete;

        /**
         * The copy assignment operator for relocating this object. Explicitly disallowed.
         */
        void operator=(const Component &) = delete;

        /**
         * The destructor for this object will remove itself from the shared ECS system manager
         * before releasing its resources.
         */
        ~Component();

        /**
         * Access a pointer to the ID associated with this object.
         * @return A constant pointer to the UUID for this object.
         */
        const boost::uuids::uuid *getID();

    protected:
        const boost::uuids::uuid *id;
    };
}

#endif //TITANOFAIR_COMPONENT_HXX
