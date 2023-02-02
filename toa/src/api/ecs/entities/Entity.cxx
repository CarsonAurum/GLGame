//
// Carson R - 1/23/23
//

// Library Includes
#include <spdlog/spdlog.h>
#include <boost/uuid/uuid_io.hpp>
// Internal Includes
#include "api/ecs/core/ECS.hxx"
#include "api/ecs/entities/Entity.hxx"
#include "app/App.hxx"

using namespace TitanOfAir::ECS;

Entity::Entity(): uuid{IDGenerator{}()}
{

    spdlog::get(App::LOG)->trace(
            "Creating a new Entity: ID({}).",
            boost::uuids::to_string(uuid));
}

Entity::Entity(Entity&& move) noexcept:
    uuid{boost::move(move.uuid)},
    components{boost::move(move.components)}
{
    spdlog::get(App::LOG)->trace(
            "Moving Entity ID({})",
            boost::uuids::to_string(uuid));
}
