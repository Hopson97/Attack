#ifndef TEST_H
#define TEST_H

#include "game.h"
#include "level.h"

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

    private:
        Level m_level;

};

}

#endif // TEST_H
