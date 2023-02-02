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

    enum ECResponse
    {

        APP_ENTY_OP_SUCCESS = 0x0100,
        APP_ENTY_OP_ERROR = 0x0101,
        APP_ENTY_PRESENT = 0x0102,
        APP_ENTY_NOT_PRESENT = 0x0103,
        APP_ENTY_OK = 0x0104,

        ENTY_CMPT_PRESENT = 105,
        ENTY_CMPT_NOT_PRESENT = 106,
        ENTY_CMPT_OP_OK = 107,
        ENTY_CMPT_OP_ERROR = 108,

        APP_CMPT_OP_SUCCESS = 200,
        APP_CMPT_OP_ERROR = 201,
        APP_CMPT_PRESENT = 202,
        APP_CMPT_NOT_PRESENT = 203,
    };

    // FWD Defs
    class Entity;

    class Component;

    class ECSystem;

    // ECS Typedefs
    typedef const boost::uuids::uuid ID;
    typedef boost::shared_mutex Mutex;
    typedef boost::uuids::random_generator IDGenerator;
    typedef const boost::tuples::tuple<Entity, ECResponse> EntityTuple;
    typedef boost::unordered::unordered_map<ID*, EntityTuple> EntityContainer;
    typedef boost::tuples::tuple<Component, ECResponse> ComponentTuple;
    typedef boost::unordered::unordered_map<ID*, ComponentTuple> ComponentContainer;
    typedef boost::unordered::unordered_set<ID*> IDSet;
}

#endif //TITANOFAIR_ECS_HXX
