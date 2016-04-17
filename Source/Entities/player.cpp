#include "player.h"

#include "tile_info.h"

#include <iostream>

Player :: Player( const Level* level )
:   m_level ( level )
{
    m_sprite.setSize( { 20, 20 } );
    m_sprite.setFillColor( sf::Color::Red );

    m_sprite.setPosition( 800, 1000 );
}

void
Player :: input ( const float dt )
{
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
    {
        m_velocity.y -= 0.2 * dt;
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
    {
        m_velocity.x -= 0.2 * dt;
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
    {
        m_velocity.x += 0.2 * dt;
    }
}

void
Player :: update ( const float dt )
{
    updateTilePosition();

    tileCollideCheck();

    m_sprite.move( m_velocity.x, m_velocity.y);

    m_velocity.x *= 0.9;
    m_velocity.y *= 0.9;
}

void
Player :: tileCollideCheck    ()
{
    sf::Vector2i p = m_tilePostion;

    if ( m_level->getTileAt( p.x - 1, p.y )->m_isSolid)
    {
        m_velocity.x = 0;
    }
}

const sf::Vector2f
Player :: getPixelPosition () const
{
   return m_sprite.getPosition();
}

void
Player :: updateTilePosition ()
{
    int x = ( m_sprite.getSize().x / 2 + m_sprite.getPosition().x ) / Tile::TILE_SIZE;;
    int y = ( m_sprite.getSize().x / 2 + m_sprite.getPosition().y ) / Tile::TILE_SIZE;

    m_tilePostion = { x, y };
}

void
Player :: draw ( sf::RenderWindow& window )
{
    window.draw( m_sprite );
}
