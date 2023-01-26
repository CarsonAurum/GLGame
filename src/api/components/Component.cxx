//
// Carson R - 1/23/23
//

// Libs
#include <spdlog/spdlog.h>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
// Local
#include "app/App.hxx"
#include "api/ecs/components/Component.hxx"

using namespace TitanOfAir;

Component::Component()
{
    auto generator = boost::uuids::random_generator{};
    this->id = new boost::uuids::uuid{generator()};
    App::shared()->add(this);
}

Component::~Component()
{
    App::shared()->remove(this);
    delete id;
}

const boost::uuids::uuid *Component::getID()
{
    return this->id;
}

