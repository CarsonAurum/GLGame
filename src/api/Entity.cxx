//
// Carson R - 1/23/23
//

#include <uuid_v4.h>
#include <spdlog/spdlog.h>
#include "api/Entity.hxx"
#include "api/API_ERRORS.hxx"
#include <algorithm>

using namespace TitanOfAir;

Entity::Entity ()
{
    UUIDv4::UUIDGenerator<std::mt19937_64> generator;
    this->id = generator.getUUID();
    spdlog::get("TitanOfAir")->trace(
            "Constructing Entity. (ID = {})",
            this->id.str());
}

