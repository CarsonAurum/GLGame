//
// Carson R - 1/23/23
//

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/thread/shared_mutex.hpp>

#include "app/App.hxx"
#include "api/ecs/core/ECS.hxx"
#include "api/ecs/entities/Entity.hxx"

using namespace TitanOfAir::ECS;


Entity::Entity()
{
    this->id = new ID{boost::uuids::random_generator{}()};
    this->installed = new IDSet{};
    this->mut = new boost::shared_mutex{};
    this->ret = new Response{};
}

Entity::Entity(const Entity& e)
{
    this->id = new ID{*e.id};
    this->installed = new IDSet{*e.installed};
    this->mut = new boost::shared_mutex{};
    this->ret = new Response{*e.ret};
}

Entity::Entity(Entity&& e) noexcept
{
    this->id = e.id;
    this->installed = e.installed;
    this->mut = new boost::shared_mutex{};
    this->ret = e.ret;
    delete e.mut;
    e.mut = new boost::shared_mutex{};
    e.id = nullptr, e.installed = nullptr, e.ret = nullptr;
}

Entity::~Entity()
{
    delete id;
    delete ret;
    delete mut;
    delete installed;
}

Entity& Entity::operator=(const Entity& lhs)
{
    this->id = new ID{*lhs.id};
    this->installed = new IDSet{*lhs.installed};
    this->mut = new boost::shared_mutex{};
    this->ret = new Response{*lhs.ret};
    return *this;
}

Entity& Entity::operator=(Entity&& lhs) noexcept
{
    this->id = lhs.id;
    this->installed = lhs.installed;
    this->mut = new boost::shared_mutex{};
    this->ret = lhs.ret;
    delete lhs.mut;
    lhs.mut = new boost::shared_mutex{};
    lhs.id = nullptr, lhs.installed = nullptr, lhs.ret = nullptr;
    return *this;
}


std::string Entity::getID() const
{
    return boost::uuids::to_string(*this->id);
}

void Entity::add(Component* c)
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