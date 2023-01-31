//
// Carson R - 1/23/23
//

#ifndef TITANOFAIR_COMPONENT_HXX
#define TITANOFAIR_COMPONENT_HXX

// Libs
#include "boost/uuid/uuid.hpp"
#include "api/ecs/core/ECS.hxx"

namespace TitanOfAir::ECS {
    /**
     * An abstract superclass representing a component in the TitanOfAir ECS system.
     */
    class Component {
    public:
        /**
         * The default constructor creates the id for this component.
         */
        Component();

        /**
         * The copy constructor for duplicating the given object.
         */
        Component(const Component&);

        /**
         * The move constructor for relocating the given object.
         */
        Component(Component&&);

        /**
         * The copy assignment operator for duplicating this object.
         */
        Component& operator=(const Component&);

        /**
         * The move assignment operator for relocating this object.
         */
        Component operator=(Component&&);

        /**
         * The destructor for this object.
         */
        ~Component();

        /**
         * Access a pointer to the ID associated with this object.
         * @return A constant pointer to the UUID for this object.
         */
        [[nodiscard]] const boost::uuids::uuid* getID();

    protected:
        const boost::uuids::uuid id;
        Response* ret;
        boost::shared_mutex* mut;
        boost::unordered::unordered_set<const boost::uuids::uuid*>* installed;
    };
}

#endif //TITANOFAIR_COMPONENT_HXX
