//
// Created by Carson Rau on 1/28/23.
//

#ifndef TITANOFAIR_RESPONSE_HXX
#define TITANOFAIR_RESPONSE_HXX

#include <boost/exception/exception.hpp>
#include <exception>

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
        APP_ENTY_OP_SUCCESS = 0100,
        APP_ENTY_OP_ERROR = 0101,
        APP_ENTY_PRESENT = 0102,
        APP_ENTY_NOT_PRESENT = 0103,
        APP_ENTY_OK = 0104,

        // [Component Codes 02xx]
        APP_CMPT_OP_SUCCESS = 0200,
        APP_CMPT_OP_ERROR = 0201,
        APP_CMPT_PRESENT = 0202,
        APP_CMPT_NOT_PRESENT = 0203,
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

#endif //TITANOFAIR_RESPONSE_HXX
