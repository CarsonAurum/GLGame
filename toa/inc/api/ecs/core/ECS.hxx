//
// Created by Carson Rau on 1/28/23.
//

#ifndef TITANOFAIR_ECS_HXX
#define TITANOFAIR_ECS_HXX

#include <boost/unordered/unordered_set.hpp>
#include <boost/unordered/unordered_map.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace TitanOfAir::ECS
{

    typedef boost::shared_mutex Mutex;

    // FWD Defs
    class Entity;

    class Component;

    class Response;

    // ECS Typedefs
    /**
     * An ID within the ECS system.
     */
    typedef const boost::uuids::uuid ID;
    typedef boost::uuids::random_generator IDGenerator;
    /**
     * A tuple containing a dynamically allocated entity and its associated response.
     *
     * Analogous to `ComponentTuple`.
     */
    typedef const boost::tuples::tuple<Entity *, Response *> EntityTuple;
    /**
     * A container relating the ID of an entity with its associated tuple.
     *
     * Analogous to `ComponentContainer`.
     */
    typedef boost::unordered::unordered_map<ID *, EntityTuple> EntityContainer;
    /**
     * A tuple containing a dynamically allocated component and its associated response.
     *
     * Analogous to `EntityTuple`.
     */
    typedef boost::tuples::tuple<Component *, Response *> ComponentTuple;
    /**
     * A container relating the ID of a component with its associated tuple.
     *
     * Analogous to `EntityContainer`.
     */
    typedef boost::unordered::unordered_map<ID *, ComponentTuple> ComponentContainer;
    /**
     * An unordered container of `TitanOfAir::ECS::ID` with O(1) complexity for most common
     * operations.
     */
    typedef boost::unordered::unordered_set<ID *> IDSet;
}

#endif //TITANOFAIR_ECS_HXX
