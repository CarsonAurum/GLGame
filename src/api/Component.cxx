//
// Carson R - 1/23/23
//

#include <uuid_v4.h>
#include <spdlog/spdlog.h>
#include "api/Component.hxx"

using namespace TitanOfAir;

Component::Component ()
{
    UUIDv4::UUIDGenerator<std::mt19937_64> generator;
    this->id = generator.getUUID();
    spdlog::get("TitanOfAir")->trace(
            "Constructing Component. (ID = {})",
            this->id.str());
}

