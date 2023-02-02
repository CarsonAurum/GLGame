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
    // FWD Defs
    class Entity;

    class Component;

    class Response;

    class ECSystem;

    // ECS Typedefs
    typedef const boost::uuids::uuid ID;
    typedef boost::shared_mutex Mutex;
    typedef boost::uuids::random_generator IDGenerator;
    typedef const boost::tuples::tuple<Entity, Response> EntityTuple;
    typedef boost::unordered::unordered_map<ID*, EntityTuple> EntityContainer;
    typedef boost::tuples::tuple<Component, Response> ComponentTuple;
    typedef boost::unordered::unordered_map<ID*, ComponentTuple> ComponentContainer;
    typedef boost::unordered::unordered_set<ID*> IDSet;

    struct ECData
    {
        ID uuid;
        Mutex mutex;
        Response* response;
        IDSet installed;
    };
}

#endif //TITANOFAIR_ECS_HXX
