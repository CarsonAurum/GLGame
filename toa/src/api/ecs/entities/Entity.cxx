//
// Carson R - 1/23/23
//

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <spdlog/spdlog.h>

#include "app/App.hxx"
#include "api/ecs/core/ECS.hxx"
#include "api/ecs/entities/Entity.hxx"

using namespace TitanOfAir::ECS;


Entity::Entity():
    uuid{new ID{IDGenerator{}()}},
    installed{new IDSet{}},
    installMutex{new Mutex{}},
    ret{new Response{}}
{
    spdlog::get(App::LOG)->trace("(%s) Entity constructed.", boost::uuids::to_string(*this->uuid));
};

Entity::Entity(const Entity& e): uuid{new ID{*e.uuid}}
{
    this->installed = new IDSet{*e.installed};
    this->installMutex = new boost::shared_mutex{};
    this->ret = new Response{*e.ret};
}

Entity::Entity(Entity&& e) noexcept
{
    this->uuid = e.uuid;
    this->installed = e.installed;
    this->installMutex = new boost::shared_mutex{};
    this->ret = e.ret;
    delete e.installMutex;
    e.installMutex = new boost::shared_mutex{};
    e.uuid = nullptr, e.installed = nullptr, e.ret = nullptr;
}

Entity::~Entity()
{
    delete uuid;
    delete ret;
    delete installMutex;
    delete installed;
}

Entity& Entity::operator=(const Entity& lhs)
{
    this->uuid = new ID{*lhs.uuid};
    this->installed = new IDSet{*lhs.installed};
    this->installMutex = new boost::shared_mutex{};
    this->ret = new Response{*lhs.ret};
    return *this;
}

Entity& Entity::operator=(Entity&& lhs) noexcept
{
    this->uuid = lhs.uuid;
    this->installed = lhs.installed;
    this->installMutex = new boost::shared_mutex{};
    this->ret = lhs.ret;
    delete lhs.installMutex;
    lhs.installMutex = new boost::shared_mutex{};
    lhs.uuid = nullptr, lhs.installed = nullptr, lhs.ret = nullptr;
    return *this;
}


std::string Entity::getID() const
{
    return boost::uuids::to_string(*this->uuid);
}

void Entity::add(Component* c)
{
    this->installMutex->lock_upgrade();
    if (installed->contains(c->getID()))
    {
        this->ret->cause = Response::ENTY_CMPT_PRESENT;
        installMutex->unlock_upgrade();
        return;
    }
    this->installMutex->unlock_upgrade_and_lock();
    this->installed->emplace(c->getID());
    this->ret->cause = Response::ENTY_CMPT_OP_OK;
}