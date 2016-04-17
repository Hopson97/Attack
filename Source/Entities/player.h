#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "entity.h"
#include "level.h"

class Player : public Entity
{
    public:
        Player  ( const Level& level );

        void
        input   ( const float dt );

    private:
        void
        uniqueUpdate  ( const float dt ) override;

        void
        checkGravity        ();

        void
        checkXTile          ( const sf::Vector2f& newPos );

        const bool
        tileSolid           ( const sf::Vector2f& newPos  ) const;

    private:
        bool m_isOnGround = false;

        constexpr static double m_walkSpeed    = 100;

        constexpr static double m_jumpSpeed    = 500;

        const Level& m_level;


};

#endif // PLAYER_H
