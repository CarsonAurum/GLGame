//
// Created by Carson Rau on 1/28/23.
//

#ifndef TITANOFAIR_RESPONSE_HXX
#define TITANOFAIR_RESPONSE_HXX

#include "boost/exception/exception.hpp"
#include <exception>

namespace TitanOfAir::ECS
{
    class Entity;

    class Component;

    /**
     * A response contains data about the result of an operation performed within the ECS context.
     *
     * Responses are exceptions that are typically returned or passed to be queried. In the event
     * that immediate handling of a response is required, the c++ exception mechanics are fully
     * accessible using objects of this type.
     *
     * Each response relies on an underlying `ActionResult` that classifies responses into multiple
     * different error domains represented by 4-digit integer values.
     */
    class Response : public boost::exception::exception, std::exception
    {
    public:
        /**
    * The ActionResult is a 4 digit code representing a more detailed response from
    * functions within this class.
    *
    * Code List:
    * [00xx]           =   General App Codes
    *      [0000]          =   APP_SUCCESS
    *      [0001]          =   APP_FAILURE
    * [01xx]           =   Entity Codes
    *      [0100]          =   APP_ENTY_OP_SUCCESS
    *      [0101]          =   APP_ENTY_OP_ERROR
    *      [0102]          =   APP_ENTY_PRESENT
    *      [0103]          =   APP_ENTY_NOT_PRESENT
    * [02xx]           =   Component Codes
    *      [0200]          =   APP_CMPT_OP_SUCCESS
    *      [0201]          =   APP_CMPT_OP_ERROR
    *      [0202]          =   APP_CMPT_PRESENT
    *      [0203]          =   APP_CMPT_NOT_PRESENT
    *
    * @see `inc/api/Except.hxx`
    */
        enum ActionResult
        {
            // [App General Codes 00xx]
            APP_SUCCESS = 0000,
            APP_FAILURE = 0001,


            // [Entity Codes 01xx]
            APP_ENTY_OP_SUCCESS = 100,
            APP_ENTY_OP_ERROR = 101,
            APP_ENTY_PRESENT = 102,
            APP_ENTY_NOT_PRESENT = 103,
            APP_ENTY_OK = 104,
            ENTY_CMPT_PRESENT = 105,
            ENTY_CMPT_NOT_PRESENT = 106,
            ENTY_CMPT_OP_OK = 107,
            ENTY_CMPT_OP_ERROR = 108,
            // [Component Codes 02xx]
            APP_CMPT_OP_SUCCESS = 200,
            APP_CMPT_OP_ERROR = 201,
            APP_CMPT_PRESENT = 202,
            APP_CMPT_NOT_PRESENT = 203,
        };

        Response();

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
