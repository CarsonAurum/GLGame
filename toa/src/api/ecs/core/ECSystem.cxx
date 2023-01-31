//
// Carson R - 1/30/2023
//

#include "api/ecs/core/ECSystem.hxx"
#include "api/ecs/entities/Entity.hxx"
#include "api/ecs/components/Component.hxx"

using namespace TitanOfAir::ECS;

ECSystem::ECSystem()
{
    this->eMutex = new boost::shared_mutex{};
    this->entities = new EntityContainer{};
    this->cMutex = new boost::shared_mutex{};
    this->components = new ComponentContainer{};
}

ECSystem::ECSystem(ECSystem &)
{

}

void ECSystem::operator=(const ECSystem &)
{

}

ECSystem::~ECSystem()
{
    eMutex->lock();
    cMutex->lock();
    assert(this->entities->empty());
    delete this->entities;
    eMutex->unlock();
    delete eMutex;

    assert(this->components->empty());
    delete this->components;
    cMutex->unlock();
    delete cMutex;
}

std::size_t ECSystem::entityCount() const
{
    return this->entities->size();
}

std::size_t ECSystem::componentCount() const
{
    return this->components->size();
}

Response ECSystem::add(Entity * e, Response * r)
{
    this->eMutex->lock_upgrade();
    if (has(e))
    {
        this->eMutex->unlock_upgrade();
        return  Response::APP_ENTY_PRESENT;
    }
    this->eMutex->unlock_upgrade_and_lock();
    auto res = this->entities->emplace(e->uuid, EntityTuple{e, r});
    this->eMutex->unlock();
    if (!res.second)
        return Response::APP_ENTY_OP_ERROR;
    return Response::APP_ENTY_OP_SUCCESS;
}

Response ECSystem::remove(Entity * e)
{
    this->eMutex->lock_upgrade();
    if (!has(e))
    {
        this->eMutex->unlock_upgrade();
        return Response::APP_ENTY_NOT_PRESENT;
    }
    this->eMutex->unlock_upgrade_and_lock();
    auto res = this->entities->erase(e->uuid);
    this->eMutex->unlock();
    if (res != 1)
        return Response::APP_ENTY_OP_ERROR;
    return Response::APP_ENTY_OP_SUCCESS;
}

bool ECSystem::has(Entity * e) const
{
    return this->entities->find(e->uuid) != this->entities->end();
}

const Response *ECSystem::getStatus(Entity * e) const
{
    this->eMutex->lock_shared();
    if (!has(e))
        return nullptr;
    auto data = this->entities->at(e->uuid);
    this->eMutex->unlock_shared();
    return const_cast<const Response*>(data.get<1>());
}

Response ECSystem::add(Component * c, Response * r)
{
    this->cMutex->lock_upgrade();
    if (has(c))
    {
        this->cMutex->unlock_upgrade();
        return  Response::APP_ENTY_PRESENT;
    }
    this->cMutex->unlock_upgrade_and_lock();
    auto res = this->components->emplace(c->getID(), ComponentTuple{c, r});
    this->cMutex->unlock();
    if (!res.second)
        return Response::APP_ENTY_OP_ERROR;
    return Response::APP_ENTY_OP_SUCCESS;
}

Response ECSystem::remove(Component * c)
{
    this->cMutex->lock_upgrade();
    if (!has(c))
    {
        this->cMutex->unlock_upgrade();
        return Response::APP_ENTY_NOT_PRESENT;
    }
    this->cMutex->unlock_upgrade_and_lock();
    auto res = this->components->erase(c->getID());
    this->cMutex->unlock();
    if (res != 1)
        return Response::APP_ENTY_OP_ERROR;
    return Response::APP_ENTY_OP_SUCCESS;
}

bool ECSystem::has(Component * c) const
{
    return this->components->find(c->getID()) != this->components->end();
}

const Response *ECSystem::getStatus(Component * c) const
{
    this->cMutex->lock_shared();
    if (!has(c))
        return nullptr;
    auto data = this->components->at(c->getID());
    this->cMutex->unlock_shared();
    return const_cast<const Response*>(data.get<1>());
}

std::size_t ECSystem::clear()
{
    this->eMutex->lock();
    size_t removed = 0;
    for(auto &entity : *entities)
    {
        delete entity.second.get<0>(), entity.second.get<1>();
        ++removed;
    }
    this->eMutex->unlock();
    this->cMutex->lock();
    for (auto &component : *components)
    {
        delete component.second.get<0>(), component.second.get<1>();
        ++removed;
    }
    this->cMutex->unlock();
    return removed;
}
