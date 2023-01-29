//
// Carson R - 1/23/23
//

// Libs
#include <spdlog/spdlog.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
// Local
#include "app/App.hxx"
#include "api/ecs/ECS.hxx"

using namespace TitanOfAir;

Component::Component(): id{boost::uuids::random_generator{}()}
{
    this->installed = new IDSet{};
    App::shared()->add(this);
}

Component::~Component()
{
    App::shared()->remove(this);
}

ID* Component::getID()
{
    return &this->id;
}

