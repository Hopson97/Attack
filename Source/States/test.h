#ifndef TEST_H
#define TEST_H

#include "game.h"
#include "level.h"
#include "player.h"

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
        Level       m_level;
        Player      m_player;

        sf::View    m_camera;

};

}

#endif // TEST_H
