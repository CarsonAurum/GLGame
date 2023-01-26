//
// Carson R - 1/23/23
//

#ifndef TITANOFAIR_COMPONENT_HXX
#define TITANOFAIR_COMPONENT_HXX

namespace TitanOfAir
{
    /**
     * An abstract superclass representing a component in the TitanOfAir ecs
     * system.
     */
    class Component
    {
    public:
        /**
         * The default constructor creates the id.
         * @note This constructor should be called from all implementing classes.
         */
        Component();

        /**
         * The copy constructor for copying this object.
         * @note This must be implemented by all subclasses.
         * @param copy The component whose data should be copied, leaving the
         * given component unchanged.
         */
        Component(const Component &copy) = delete;

        /**
         * The move constructor for relocating this object.
         * @note This must be implemented by all subclasses.
         * @param move The component whose data should be moved to the target
         * destination.
         * @post This constructor should clear the parameter's values by calling
         * its destructor.
         */
        Component(Component &&move) = delete;

        virtual ~Component() = delete;

    private:
    };
}

#endif //TITANOFAIR_COMPONENT_HXX
