//
// Carson R - 1/23/23
//

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "app/App.hxx"
#include "api/ecs/entities/Entity.hxx"

using namespace TitanOfAir;


Entity::Entity(): id{boost::uuids::random_generator{}()}
{
    // Add to ECS
    auto res = App::shared()->add(this);
    if(!res.is(Response::APP_ENTY_OP_SUCCESS))
        throw boost::move(res);
}

Entity::~Entity()
{
    App::shared()->remove(this);
}

const boost::uuids::uuid* Entity::getID() const
{
    return &this->id;
}
