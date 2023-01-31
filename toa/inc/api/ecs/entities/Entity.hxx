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
    class Component;
    class ECSystem;

    /**
     * @brief An abstract superclass representing an entities in an ECSystem.
     * @details Entities should not be placed on the heap. They are fully copy and move
     * constructable. All data within these classes is dynamically stored, making overhead for
     * copy and move minimal.
     * @details Entities are thread-safe classes that can be accessed safely concurrently. All
     * public functions are guaranteed to have this safety. Protected members are **NOT**
     * guaranteed to have this safety, therefore the built-in mutex may be used to control access to
     * these unsafe resources.
     *
     * @qualifier "Copy Assignable"
     * @qualifier "Copy Constructable"
     * @qualifier "Default Constructable"
     * @qualifier "Equality Comparable"
     * @qualifier "Move Assignable"
     * @qualifier "Move Constructable"
     */
    class Entity
    {
    public:
        /**
         * @brief An empty constructor initializing the heap data to be managed by this instance.
         * @details Entities created using this empty constructor will receive a new
         * `UUID`, a new Response object, and other internal details necessary
         * for the functioning of a distinct entity.
         */
        Entity();

        /**
         * @brief A copy constructor capable of duplicating a given Entity.
         * @param copy The entity to copy.
         * @post This object contains an independent duplicate set of all data within the given
         * instance.
         */
        Entity(const Entity& copy);

        /**
         * @brief A move constructor capable of relocating a given Entity.
         * @param move The entity to move.
         * @post This object now contains unique access to all of the data from the given instance.
         */
        Entity(Entity&& move) noexcept;

        /**
         * @brief The copy assignment operator allowing duplication of an Entity.
         * @param lhs The entity to copy.
         * @return A reference to a new entity containing a copy of all data within the given
         * Entity.
         */
        Entity& operator=(const Entity& lhs);

        /**
         * @brief The move assignment operator allowing relocation of an Entity.
         * @details Move assignment is made accessible via the following notation:
         * @code{.cpp}
         * Entity rhs = boost::move(lhs);   // or std::move(lhs)
         * @endcode
         * @param lhs The entity to move.
         * @return A reference to a new entity containing unique access to all data from `lhs`.
         */
        Entity& operator=(Entity&& lhs) noexcept;

        /**
         * @brief The destructor for freeing all resources associated with this entity.
         * @details All requests from any threads currently in the queue for completion will be
         * allowed to complete before the thread calling for destruction is allowed to free resources.
         */
        ~Entity();

        /**
         * @brief Access a string version of this Entity's ID.
         * @return A string representing the hexadecimal digits of this Entity's universally unique
         * ID (`UUID`).
         */
        [[nodiscard]] std::string getID() const;

        /**
         * @brief Add a new Component to this Entity's list of associated Components.
         * @post If the addition of the Component is successful
         * @post If there is an unidentified error adding the component, this Entity's Response will
         * be updated to Response::ENTY_CMPT_OP_ERROR.
         */
        void add(Component* c);

    protected:
        /**
         * @brief The universally unique identifier (UUID) for this Entity.
         */
        ID* uuid;
        /**
         * @brief A pointer to access this object's associated Response object.
         */
        Response* ret;
        /**
         * @brief The mutex to use when synchronizing access to the Entity::installed set.
         */
        Mutex* installMutex;
        /**
         * @brief A set containing all a pointer to each Component::uuid that is associated with this
         * Entity with the ECSystem.
         */
        IDSet* installed;
    private:
        friend ECSystem;
    };
}

#endif //TITANOFAIR_ENTITY_HXX
