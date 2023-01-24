//
// Carson R - 1/10/2023
//

#ifndef TITANOFAIR_APP_HXX
#define TITANOFAIR_APP_HXX

#include <vector>

namespace TitanOfAir
{
    class App
    {
    public:
        App(App&) = delete;
        void operator =(const App&) = delete;
        ~App() = delete;
        static App* getInstance();
    protected:
        App();
    private:
        std::vector<char*> entities;
        std::vector<char*> components;
    };
}

#endif //TITANOFAIR_APP_HXX
