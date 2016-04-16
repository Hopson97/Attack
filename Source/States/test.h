#ifndef TEST_H
#define TEST_H

#include "game.h"

namespace State
{

class Test : public State_Base
{
    public:
        Test    ( Game* game);

        ~Test   () {}

        void
        input   ( const double dt ) override;

        void
        update  ( const double dt ) override;

        void
        draw  ( const double dt ) override;

    protected:
        Game* mGame;

        sf::Text testText;
};

}

#endif // TEST_H
