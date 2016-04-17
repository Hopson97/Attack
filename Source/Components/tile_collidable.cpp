#include "tile_collidable.h"

#include "tile_info.h"

#include "tile_map_component_funcs.h"

namespace Component
{

Tile_Collidable :: Tile_Collidable( Entity& entity, const Level& level )
:   m_entity ( entity )
,   m_level  ( level )
{
}

void
Tile_Collidable :: update ( const float dt )
{
    checkLeftCollide();
    checkRightCollide();
    checkUpCollide();
}

void
Tile_Collidable :: checkXTile ( const sf::Vector2f& newPos )
{
    if ( tileSolid ( m_level, newPos ) )
    {
        m_entity.resetXVelocity();
    }
}

void
Tile_Collidable :: checkYTile ( const sf::Vector2f& newPos )
{
    if ( tileSolid ( m_level, newPos ) )
    {
        m_entity.resetYVelocity();
    }
}

void
Tile_Collidable :: checkLeftCollide    ()
{
    sf::Vector2f newPos = getNextPosition ( m_entity );

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
    sf::Vector2f newPos = getNextPosition ( m_entity );

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
    sf::Vector2f newPos = getNextPosition ( m_entity );

    if ( m_entity.getVelocity().y < 0 )
    {
        checkYTile( newPos );

        newPos.x += m_entity.getSpriteSize().x - 1;

        checkYTile( newPos );
    }
}

} //Namespace Component
