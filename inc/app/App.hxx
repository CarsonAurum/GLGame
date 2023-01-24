//
// Carson R - 1/10/2023
//

#ifndef TITANOFAIR_APP_HXX
#define TITANOFAIR_APP_HXX

namespace TitanOfAir
{
    class App
    {
    public:
        App(App&) = delete;
        void operator =(const App&) = delete;
        static App* getInstance();
    protected:
        App();
    };
}

#endif //TITANOFAIR_APP_HXX
