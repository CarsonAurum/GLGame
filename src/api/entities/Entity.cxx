//
// Carson R - 1/23/23
//

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "api/ecs/entities/Entity.hxx"

using namespace TitanOfAir;


Entity::Entity()
{
    auto generator = boost::uuids::random_generator{};
    this->id = new boost::uuids::uuid;
    *(this->id) = generator();
}

boost::uuids::uuid* Entity::getID() {
    this->id;
}
