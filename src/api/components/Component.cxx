//
// Carson R - 1/23/23
//

// Libs
#include <spdlog/spdlog.h>
#include <boost/uuid/uuid_generators.hpp>
// Local
#include "app/App.hxx"
#include "api/ecs/ECS.hxx"

using namespace TitanOfAir;

Component::Component(): id{boost::uuids::random_generator{}()}
{
    this->installed = new IDSet{};
    this->ret = new Response{};
    this->mut = new boost::shared_mutex{};
    auto res = App::shared()->add(this, ret);
    if (!res.is(Response::APP_CMPT_OP_SUCCESS))
        throw boost::move(res);
}

Component::~Component()
{
    App::shared()->remove(this);
    delete ret; delete mut; delete installed;
}

ID* Component::getID()
{
    return &this->id;
}

