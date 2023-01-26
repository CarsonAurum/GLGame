//
// Carson R - 1/23/23
//

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "app/App.hxx"
#include "api/ecs/entities/Entity.hxx"
#include "api/Except.hxx"

using namespace TitanOfAir;


Entity::Entity()
{
    // Make ID
    auto generator = boost::uuids::random_generator{};
    this->id = new boost::uuids::uuid{generator()};
    // Add to ECS
    auto res = App::shared()->add(this);
    if(res != App::APP_ENTY_OP_SUCCESS)
        throw TitanOfAir::Exception{res};

}

Entity::~Entity()
{
    App::shared()->remove(this);
    delete id;
}

const boost::uuids::uuid *Entity::getID()
{
    return this->id;
}
