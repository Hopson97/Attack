#include "tile_collidable.h"

#include "tile_info.h"

Tile_Collidable :: Tile_Collidable( Entity& entity, const Level& level )
:   m_entity ( entity )
,   m_level  ( level )
{
}

void
Tile_Collidable :: update ()
{
    checkLeftCollide();
    checkRightCollide();
    checkUpCollide();
}

void
Tile_Collidable :: checkXTile ( const sf::Vector2f& newPos )
{
    if ( tileSolid ( newPos ) )
    {
        m_entity.resetXVelocity();
    }
}

void
Tile_Collidable :: checkLeftCollide    ()
{
    sf::Vector2f newPos = getNextPosition ();

    if ( m_entity.getVelocity().x < 0 )
    {
        checkXTile( newPos );

        newPos.y += m_entity.getSpriteSize().y - 1;

        checkXTile( newPos );
    }
}

void
Tile_Collidable :: checkRightCollide   ()
{
    sf::Vector2f newPos = getNextPosition ();

    newPos.x += m_entity.getSpriteSize().x;

    if ( m_entity.getVelocity().x > 0 )
    {
        checkXTile( newPos );

        newPos.y += m_entity.getSpriteSize().y - 1;

        checkXTile( newPos );
    }
}

void
Tile_Collidable :: checkUpCollide      ()
{
    sf::Vector2f newPos = getNextPosition ();

    if ( m_entity.getVelocity().y < 0 )
    {
        if ( tileSolid( newPos ) )
        {
            m_entity.resetYVelcoity();
        }
    }
}

//Tells where the tile position in the area given is solid or not
const bool
Tile_Collidable :: tileSolid ( const sf::Vector2f& newPos ) const
{
    return m_level.getTileAt( newPos.x / Tile::TILE_SIZE,
                               newPos.y / Tile::TILE_SIZE
                             )
                             ->m_isSolid;
}

//interpolates the next position of the entity
const sf::Vector2f
Tile_Collidable :: getNextPosition () const
{
    sf::Vector2f newPos;    // The new tile map position of the player
    newPos.x = m_entity.getSpritePosition().x + m_entity.getVelocity().x;
    newPos.y = m_entity.getSpritePosition().y + m_entity.getVelocity().y;

    return newPos;
}
