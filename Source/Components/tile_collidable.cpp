#include "tile_collidable.h"

#include "tile_info.h"

#include "tile_map_component_funcs.h"

namespace Component
{

Tile_Collidable :: Tile_Collidable( Entity& entity, const Level& level, Gravity_Particles* dirt )
:   m_entity        ( entity )
,   m_level         ( level )
,   m_dirtParticles ( dirt )
{
}

void
Tile_Collidable :: update ( const float dt )
{
    checkLeftCollide    ( dt );
    checkRightCollide   ( dt);
    checkUpCollide      ( dt);
}

void
Tile_Collidable :: checkXTile ( const sf::Vector2f& newPos )
{
    if ( tileSolid ( m_level, newPos ) )
    {
        addParticles();
        m_entity.resetXVelocity();
    }
}

void
Tile_Collidable :: checkYTile ( const sf::Vector2f& newPos )
{
    if ( tileSolid ( m_level, newPos ) )
    {
        addParticles();
        m_entity.resetYVelocity();
    }
}

void
Tile_Collidable :: checkLeftCollide    ( const float dt )
{
    sf::Vector2f newPos = getNextPosition ( m_entity, dt );

    if ( m_entity.getVelocity().x < 0 )
    {
        checkXTile( newPos );

        newPos.y += m_entity.getSpriteSize().y - 1;

        checkXTile( newPos );
    }
}

void
Tile_Collidable :: checkRightCollide   ( const float dt )
{
    sf::Vector2f newPos = getNextPosition ( m_entity, dt );

    newPos.x += m_entity.getSpriteSize().x;

    if ( m_entity.getVelocity().x > 0 )
    {
        checkXTile( newPos );

        newPos.y += m_entity.getSpriteSize().y - 1;

        checkXTile( newPos );
    }
}

void
Tile_Collidable :: checkUpCollide      ( const float dt )
{
    sf::Vector2f newPos = getNextPosition ( m_entity, dt );

    if ( m_entity.getVelocity().y < 0 )
    {
        checkYTile( newPos );

        newPos.x += m_entity.getSpriteSize().x - 1;

        checkYTile( newPos );
    }
}

void
Tile_Collidable :: addParticles ()
{
    if ( m_dirtParticles )
    {
        m_dirtParticles->addParticles(  5,
                                       {m_entity.getSpritePosition().x + m_entity.getSpriteSize().x / 2,
                                        m_entity.getSpritePosition().y + m_entity.getSpriteSize().y / 2 },
                                       {-m_entity.getVelocity().x * 2,
                                       ( m_entity.getVelocity().y > 0) ? //The ternary operators here guarntee the particle to go up
                                        -m_entity.getVelocity().y / 10 :
                                         m_entity.getVelocity().y / 10 } );
    }
}

} //Namespace Component
