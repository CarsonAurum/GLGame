//
// Created by Carson Rau on 1/28/23.
//

#ifndef TITANOFAIR_RESPONSE_HXX
#define TITANOFAIR_RESPONSE_HXX

#include <boost/exception/exception.hpp>
#include <exception>

#include "api/ecs/core/ECS.hxx"

namespace TitanOfAir::ECS
{

    class Response : public boost::exception::exception, std::exception
    {
    public:
        enum ActionResult
        {
            APP_SUCCESS = 0x0000,
            APP_FAILURE = 0x0001,

            APP_ENTY_OP_SUCCESS = 0x0100,
            APP_ENTY_OP_ERROR = 0x0101,
            APP_ENTY_PRESENT = 0x0102,
            APP_ENTY_NOT_PRESENT = 0x0103,
            APP_ENTY_OK = 0x0104,

            ENTY_CMPT_PRESENT = 105,
            ENTY_CMPT_NOT_PRESENT = 106,
            ENTY_CMPT_OP_OK = 107,
            ENTY_CMPT_OP_ERROR = 108,

            APP_CMPT_OP_SUCCESS = 200,
            APP_CMPT_OP_ERROR = 201,
            APP_CMPT_PRESENT = 202,
            APP_CMPT_NOT_PRESENT = 203,
        };

        Response();

        Response(const Response &) = default;

        Response(Response &&) = default;

        Response &operator=(const Response &) = default;

        Response &operator=(Response &&) = default;

        Response(ActionResult);

        virtual const char *what() const noexcept;

        unsigned short getCode();

        bool is(ActionResult);

    protected:
        friend class Entity;

        friend class Component;

    private:
        ActionResult cause;
    };
}
#endif //TITANOFAIR_RESPONSE_HXX
