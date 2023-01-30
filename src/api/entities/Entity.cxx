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
    this->installed = new IDSet{};
    this->mut = new boost::shared_mutex{};
    this->ret = new Response{};
    auto res = App::shared()->add(this, ret);
    if(!res.is(Response::APP_ENTY_OP_SUCCESS))
        throw boost::move(res);
}

Entity::~Entity()
{
    mut->lock();
    App::shared()->remove(this);
    mut->unlock();
    delete ret; delete mut; delete installed;
}

const boost::uuids::uuid* Entity::getID() const
{
    return &this->id;
}

void Entity::add(Component * c, bool recurse)
{
    mut->lock_upgrade();
    if (installed->contains(c->getID()))
    {

    }
}
