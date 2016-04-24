#ifndef TEST_H
#define TEST_H

#include "game.h"
#include "level.h"
#include "player.h"
#include "bullet.h"

#include "Particles/gravity_particles.h"

#include "test_enemy.h"

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

        Gravity_Particles      m_bloodParticles;
        Gravity_Particles      m_dirtParticles;

        std::vector<std::unique_ptr<Bullet>> m_bullets;

        std::vector<std::unique_ptr<Test_Enemy>> m_enemies;
        sf::Clock m_enemyAdder;

        bool                m_isParticlesOn = true;
};

}

#endif // TEST_H
