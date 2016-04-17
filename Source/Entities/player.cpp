#include "player.h"

#include "tile_info.h"

#include <iostream>

Player :: Player( const Level* level )
:   m_level ( level )
{
    m_sprite.setSize( { Tile::TILE_RECT } );
    m_sprite.setFillColor( sf::Color::Red );

    m_sprite.setPosition( 1000, 1000 );

    updateTilePosition();
}

void
Player :: input ( const float dt )
{
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) && m_isOnGround )
    {
        m_velocity.y -= m_jumpSpeed * dt;
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
    {
        m_velocity.x -= m_walkSpeed * dt;
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
    {
        m_velocity.x += m_walkSpeed * dt;
    }
}

void
Player :: update ( const float dt )
{
    checkLeftCollide    ();
    checkRightCollide   ();
    checkUpCollide      ();
    checkGravity        ();

    m_sprite.move( m_velocity.x, m_velocity.y);

    updateTilePosition();

    m_velocity.x *= 0.8;

}

void
Player :: checkXTile ( const sf::Vector2f& newPos )
{
    if ( tileSolid ( newPos ) )
    {
        m_velocity.x = 0;
    }
}

void
Player :: checkLeftCollide    ()
{
    sf::Vector2f newPos;    // The new tile map position of the plauer
    newPos.x = m_sprite.getPosition().x + m_velocity.x;
    newPos.y = m_sprite.getPosition().y + m_velocity.y;

    if ( m_velocity.x < 0 )
    {
        checkXTile( newPos );

        newPos.y += m_sprite.getSize().y - 1;

        checkXTile( newPos );
    }
}

void
Player :: checkRightCollide   ()
{
    sf::Vector2f newPos;
    newPos.x = m_sprite.getPosition().x + m_velocity.x;
    newPos.y = m_sprite.getPosition().y + m_velocity.y;

    newPos.x += m_sprite.getSize().x;

    if ( m_velocity.x > 0 )
    {
        checkXTile( newPos );

        newPos.y += m_sprite.getSize().y - 1;

        checkXTile( newPos );
    }
}

void
Player :: checkUpCollide      ()
{
    sf::Vector2f newPos;
    newPos.x = m_sprite.getPosition().x + m_velocity.x;
    newPos.y = m_sprite.getPosition().y + m_velocity.y;

    if ( m_velocity.y < 0 )
    {
        if ( tileSolid( newPos ) )
        {
            m_velocity.y = 0;
        }
    }
}

void
Player :: checkGravity        ()
{
    sf::Vector2f newPos;
    newPos.x = m_sprite.getPosition().x + m_velocity.x;
    newPos.y = m_sprite.getPosition().y + m_velocity.y + m_sprite.getSize().y;

    float newPosRight = newPos.x + m_sprite.getSize().x; //To check the right bound of the player

    if ( !tileSolid ( newPos ) && !tileSolid ( { newPosRight, newPos.y } ) )
    {
        m_isOnGround = false;
    }

    //Apply gravity if off the ground
    if ( !m_isOnGround )
    {
        m_velocity.y += m_gravity;

        if ( tileSolid( newPos ) || tileSolid ( { newPosRight, newPos.y } ) )
        {
            m_velocity.y = 0;
            m_isOnGround = true;
        }
    }
}

const bool
Player :: tileSolid ( const sf::Vector2f& newPos ) const
{
    return m_level->getTileAt( newPos.x / Tile::TILE_SIZE,
                               newPos.y / Tile::TILE_SIZE
                             )
                             ->m_isSolid;
}

const sf::Vector2f
Player :: getPixelPosition () const
{
   return m_sprite.getPosition();
}

void
Player :: updateTilePosition ()
{
    int x = m_sprite.getPosition().x  / Tile::TILE_SIZE;;
    int y = m_sprite.getPosition().y  / Tile::TILE_SIZE;

    m_tilePostion = { x, y };
}

void
Player :: draw ( sf::RenderWindow& window )
{
    window.draw( m_sprite );
}
