#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "level.h"

class Player
{
    public:
        Player( const Level* level );

        void
        input ();

        void
        update ( const float dt );

        void
        draw ( const sf::RenderWindow& window );

    private:
        void
        updateTilePosition;

    private:
        sf::RectangleShape  m_sprite;

        sf::Vector2i        m_tilePostion;

        const Level*        m_level;
};

#endif // PLAYER_H
