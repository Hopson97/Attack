#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>

namespace winInfo
{
    constexpr int HEIGHT = 700;
    constexpr int WIDTH  = 1280;
}

class Window
{
    public:
        Window();

        sf::RenderWindow&
        get();

        void
        clear ( const sf::Color& colour = { 0, 0, 0 } );

        void
        update ();

        const bool
        isOpen ();

        void
        close ();

    private:
        void
        winEvents ();


    private:
        sf::RenderWindow m_window;
};

#endif // WINDOW_H
