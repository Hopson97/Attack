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
        glDraw  ( const double dt ) override;

        void
        sfDraw  ( const double dt ) override;

    protected:
        Game* mGame;
};

}

#endif // TEST_H
