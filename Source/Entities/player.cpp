#include "player.h"

#include "tile_info.h"

#include "tile_collidable.h"

Player :: Player(  const Level& level  )
:   Entity  ( { 50, 150 }, { 1000, 50 }  )
,   m_level ( level )
{
    updateTilePosition();
}

void
Player :: input ( const float dt )
{
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) && m_isOnGround )
    {
        changeVelocity (  0, -m_jumpSpeed * dt );
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
    {
        changeVelocity ( -m_walkSpeed * dt, 0 );
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
    {
        changeVelocity ( m_walkSpeed * dt, 0 );
    }
}

void
Player :: uniqueUpdate ( const float dt )
{
    Tile_Collidable c ( *this, m_level );

    c.update();

    checkGravity        ();


}

void
Player :: checkGravity        ()
{
    sf::Vector2f newPos;
    newPos.x = getSpritePosition().x + getVelocity().x;
    newPos.y = getSpritePosition().y + getVelocity().y + getSpriteSize().y;

    float newPosRight = newPos.x + getSpriteSize().x; //To check the right bound of the player

    if ( !tileSolid ( newPos ) && !tileSolid ( { newPosRight, newPos.y } ) )
    {
        m_isOnGround = false;
    }

    //Apply gravity if off the ground
    if ( !m_isOnGround )
    {
        changeVelocity( 0,  m_gravity );

        if ( tileSolid( newPos ) || tileSolid ( { newPosRight, newPos.y } ) )
        {
            resetYVelcoity();
            m_isOnGround = true;
        }
    }
}

const bool
Player :: tileSolid ( const sf::Vector2f& newPos ) const
{
    return m_level.getTileAt( newPos.x / Tile::TILE_SIZE,
                               newPos.y / Tile::TILE_SIZE
                             )
                             ->m_isSolid;
}

