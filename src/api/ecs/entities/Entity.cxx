//
// Carson R - 1/23/23
//

#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"

#include "app/App.hxx"
#include "api/ecs/entities/Entity.hxx"

using namespace TitanOfAir;


Entity::Entity(): id{boost::uuids::random_generator{}()}
{
    // Add to ECS
    this->installed = new IDSet{};
    this->mut = new boost::shared_mutex{};
    this->ret = new Response{};
}

Entity::~Entity()
{
    delete ret;
    delete mut;
    delete installed;
}

const boost::uuids::uuid* Entity::getID() const
{
    return &this->id;
}

void Entity::add(Component * c)
{
    this->mut->lock_upgrade();
    if (installed->contains(c->getID()))
    {
        this->ret->cause = Response::ENTY_CMPT_PRESENT;
        mut->unlock_upgrade();
        return;
    }
    this->mut->unlock_upgrade_and_lock();
    this->installed->emplace(c->getID());
    this->ret->cause = Response::ENTY_CMPT_OP_OK;
}
