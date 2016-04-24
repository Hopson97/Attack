#ifndef WORLD_H
#define WORLD_H

#include "game.h"
#include "level.h"
#include "player.h"
#include "bullet.h"

#include "Particles/gravity_particles.h"

#include "test_enemy.h"

typedef std::unique_ptr<Test_Enemy> EnemyPtr;
typedef std::unique_ptr<Bullet>     BulletPtr;
typedef Gravity_Particles           GravParts;

class World
{
    public:
        World( Game& game );

        void
        input           ();

        void
        update          ( const float dt );

        void
        draw            ( sf::RenderWindow& window );

        void
        addBullet       ();

        void
        addEye          ();

        const Player&
        getPlayer       () const;

    private:
        void
        iterateEntities ( const float dt );

        void
        iterateBullets  ( const float dt );

        void
        iterateEnemies  ( const float dt );

    private:
        Game&   m_game;
        Level   m_level;
        Player  m_player;

        GravParts   m_blood;
        GravParts   m_dirt;

        std::vector<EnemyPtr> m_enemies;
        std::vector<BulletPtr>     m_bullets;
};

#endif // WORLD_H
