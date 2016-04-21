#ifndef BULLET_H
#define BULLET_H

#include "game.h"
#include "entity.h"
#include "level.h"
#include "player.h"
#include "window.h"

#include "Particles/dynamic_particle_batch.h"

class Bullet    :   public Entity
{
    public:
        Bullet      ( const Level& level, const Game& game, const Player& player, Window& window, const sf::Vector2f& targetLocation, GravityParticles& particles );

        bool
        isFallen    () const;

    private:
        void
        uniqueUpdate ( const float dt ) override;

        const int   speed = 1600;

        float       m_lifetime = 3.0f; //Lifetime after fallen to ground
        bool        m_isFallen = false;
        sf::Clock   m_eraseClock; //Clock to determine when the bullet should be deleted
};

#endif // BULLET_H
