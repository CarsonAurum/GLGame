//
// Carson R - 1/23/23
//

#include <cstdlib>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "api/entities/Entity.hxx"

using namespace TitanOfAir;


Entity::Entity()
{
    auto generator = boost::uuids::random_generator{};
    this->id = static_cast<boost::uuids::uuid *>(malloc(sizeof(boost::uuids::uuid)));
    *(this->id) = generator();
}
