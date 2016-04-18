#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "game.h"
#include "entity.h"
#include "level.h"
#include "animation.h"

class Player : public Entity
{
    public:
        Player  ( const Level& level, const Game& game );

        void
        input   ( const float dt );

    private:
        void
        uniqueUpdate  ( const float dt ) override;

        void
        checkGravity        ();

        const bool
        tileSolid           ( const sf::Vector2f& newPos  ) const;

    private:
        constexpr static double m_walkSpeed    = 100;

        constexpr static double m_jumpSpeed    = 500;

        const Level& m_level;

        Animation m_walkAnim;


};

#endif // PLAYER_H
