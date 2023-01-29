//
// Created by Carson Rau on 1/28/23.
//

#ifndef TITANOFAIR_ECS_HXX
#define TITANOFAIR_ECS_HXX

#include <boost/unordered/unordered_map.hpp>

#include "app/Response.hxx"
#include "entities/Entity.hxx"
#include "components/Component.hxx"

namespace TitanOfAir
{
    typedef const boost::uuids::uuid ID;
    typedef const boost::tuples::tuple<Entity*, Response*> EntityTuple;
    typedef boost::unordered::unordered_map<ID*, EntityTuple> EntityContainer;
    typedef boost::tuples::tuple<Component*, Response*> ComponentTuple;
    typedef boost::unordered::unordered_map<ID*, ComponentTuple> ComponentContainer;
    typedef boost::unordered::unordered_set<ID*> IDSet;
}

#endif //TITANOFAIR_ECS_HXX
