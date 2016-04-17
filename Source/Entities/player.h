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
        tileCollideCheck    ();

    private:
        sf::RectangleShape  m_sprite;

        sf::Vector2i        m_tilePostion;

        const Level*        m_level;

        sf::Vector2f        m_velocity;
};

#endif // PLAYER_H
