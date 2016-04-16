#ifndef GAME_H
#define GAME_H

#include "Util/window.h"

#include "States/handler.h"

class Game
{
    public:
        Game    ();

        void
        runLoop ();

        inline State::Handler&
        states  () { return m_states; }

    private:
        Window m_window;
        State::Handler m_states;

        const double
        calculateDeltaTime ( sf::Clock& c, sf::Time& t );
};

#endif // GAME_H
