//
// Created by Carson Rau on 1/28/23.
//

#include "app/Response.hxx"

using namespace TitanOfAir;

Response::Response()
{
    this->cause = APP_ENTY_OK;
}

Response::Response(ActionResult cause)
{
    this->cause = cause;
}

const char *Response::what() const noexcept
{
    switch (this->cause)
    {
        case ActionResult::APP_SUCCESS: return "App Success";
        case ActionResult::APP_FAILURE: return "App Failure";

        case ActionResult::APP_ENTY_OP_SUCCESS: return "Entity Operation Success";
        case ActionResult::APP_ENTY_OP_ERROR: return "Entity Operation Failure";
        case ActionResult::APP_ENTY_PRESENT: return "Entity Present";
        case ActionResult::APP_ENTY_NOT_PRESENT: return "Entity Not Present";

        case ActionResult::APP_CMPT_OP_SUCCESS: return "Component Operation Success";
        case ActionResult::APP_CMPT_OP_ERROR: return "Component Operation Failure";
        case ActionResult::APP_CMPT_PRESENT: return "Component Present";
        case ActionResult::APP_CMPT_NOT_PRESENT: return "Component Not Present";

        default: return "";

    }
}

unsigned short Response::getCode()
{
    return this->cause;
}

bool Response::is(Response::ActionResult res)
{
    return this->getCode() == res;
}