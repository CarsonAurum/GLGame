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
     * Each response relies on an underlying Response::ActionResult that classifies responses into multiple
     * different error domains represented by 4-digit base-16 integer values.
     */
    class Response : public boost::exception::exception, std::exception
    {
    public:
        /**
         * The ActionResult is a 4 digit code representing a more detailed response from
         * functions within this class.
         *
         * | Code Domain | Domain Description        |
         * | ----------- | ------------------------- |
         * |     00xx    | Generalized App responses |
         * |     01xx    | Entity responses          |
         * |     02xx    | Component responses       |
         */
        enum ActionResult
        {
            // [App General Codes 00xx]
            /**
             * @brief A generalized success code.
             * @details RAW = 0x0000
             */
            APP_SUCCESS = 0x0000,
            /**
             * @brief A generalized failure code.
             * @details RAW = 0x0001
             */
            APP_FAILURE = 0x0001,


            // [Entity Codes 01xx]
            /**
             * @brief A generalized operation success within an ECSystem context.
             * @details RAW = 0x0100
             */
            APP_ENTY_OP_SUCCESS = 0x0100,
            /**
             * @brief A generalized operation error within an ECSystem context.
             * @details RAW = 0x0101
             */
            APP_ENTY_OP_ERROR = 0x0101,
            /**
             * @brief Indicates the presence of an Entity within an ECSystem.
             * @details RAW = 0x0102
             */
            APP_ENTY_PRESENT = 0x0102,
            /**
             * @brief Indicates the lack of an Entity within an ECSystem.
             * @details RAW = 0x0103
             */
            APP_ENTY_NOT_PRESENT = 0x0103,
            /**
             * @brief Indicates a Response initialized by an Entity.
             * @details RAW = 0x0104
             */
            APP_ENTY_OK = 0x0104,
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
        Response(const Response&) = default;
        Response(Response&&) = default;
        Response& operator =(const Response&) = default;
        Response& operator =(Response&&) = default;

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
