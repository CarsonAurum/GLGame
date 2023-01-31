//
// Carson R - 1/23/23
//

// Libs
#include "spdlog/spdlog.h"
#include "boost/uuid/uuid_generators.hpp"
// Local
#include "app/App.hxx"
#include "api/ecs/core/ECS.hxx"
#include "api/ecs/components/Component.hxx"


using namespace TitanOfAir::ECS;

Component::Component(): id{boost::uuids::random_generator{}()}
{
    this->installed = new IDSet{};
    this->ret = new Response{};
    this->mut = new boost::shared_mutex{};
}

Component::~Component()
{
    delete ret;
    delete mut;
    delete installed;
}

ID* Component::getID()
{
    return &this->id;
}

