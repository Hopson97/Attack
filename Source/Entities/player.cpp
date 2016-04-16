#include "player.h"

#include "tile_info.h"

Player :: Player( const Level* level )
:   m_level ( level )
{
    m_sprite.setSize( { 20, 20 } );
    m_sprite.setFillColor( sf::Color::Red );

    m_sprite.setPosition( 500, 500 );
}

void
Player :: input ()
{

}

void
Player :: update ( const float dt )
{

}

void
Player :: draw ( const sf::RenderWindow& window )
{

}
