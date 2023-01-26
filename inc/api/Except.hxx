//
// Carson R - 1/26/2023
//

#ifndef TITANOFAIR_EXCEPT_HXX
#define TITANOFAIR_EXCEPT_HXX

#include <exception>

namespace TitanOfAir
{
    class Exception : public std::exception
    {
    public:
        Exception(App::ActionResult);

        virtual const char *what() const noexcept;

        unsigned short getCode();

    private:
        App::ActionResult cause;
    };

    Exception::Exception(App::ActionResult cause)
    {
        this->cause = cause;
    }

    const char *Exception::what() const noexcept
    {
        switch (this->cause)
        {
            case App::APP_SUCCESS: return "App Success";
            case App::APP_FAILURE: return "App Failure";

            case App::APP_ENTY_OP_SUCCESS: return "Entity Operation Success";
            case App::APP_ENTY_OP_ERROR: return "Entity Operation Failure";
            case App::APP_ENTY_PRESENT: return "Entity Present";
            case App::APP_ENTY_NOT_PRESENT: return "Entity Not Present";

            case App::APP_CMPT_OP_SUCCESS: return "Component Operation Success";
            case App::APP_CMPT_OP_ERROR: return "Component Operation Failure";
            case App::APP_CMPT_PRESENT: return "Component Present";
            case App::APP_CMPT_NOT_PRESENT: return "Component Not Present";

            default: return "";

        }
    }

    unsigned short Exception::getCode()
    {
        return this->cause;
    }
}
#endif //TITANOFAIR_EXCEPT_HXX
