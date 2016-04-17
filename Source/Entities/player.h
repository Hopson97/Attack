#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "level.h"

class Player
{
    public:
        Player  ( const Level* level );

        void
        input   ( const float dt );

        void
        update  ( const float dt );

        void
        draw    ( sf::RenderWindow& window );

        const sf::Vector2f
        getPixelPosition () const;

    private:
        void
        updateTilePosition ();

        void
        checkLeftCollide    ();

        void
        checkRightCollide   ();

        void
        checkUpCollide      ();

        void
        checkGravity        ();

        void
        checkXTile          ( const sf::Vector2f& newPos );

        const bool
        tileSolid           ( const sf::Vector2f& newPos  ) const;

    private:
        sf::RectangleShape  m_sprite;

        sf::Vector2i        m_tilePostion;

        const Level*        m_level;

        sf::Vector2f        m_velocity;

        bool m_isOnGround = false;

        constexpr static double m_walkSpeed    = 70;

        constexpr static double m_jumpSpeed    = 1000;

        constexpr static double m_gravity      = 0.2;
};

#endif // PLAYER_H
