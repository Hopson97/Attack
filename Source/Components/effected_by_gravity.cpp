#include "effected_by_gravity.h"

#include "tile_map_component_funcs.h" //tileSolid(), getNextPosition()

namespace Component
{

Effected_By_Gravity :: Effected_By_Gravity ( Entity& entity, const Level& level )
:   m_entity ( entity )
,   m_level  ( level  )
{

}

void
Effected_By_Gravity :: update ( const float dt )
{
    checkIfOnGround();
    applyGravity();
}

void
Effected_By_Gravity :: checkIfOnGround ()
{
    sf::Vector2f newPos = getNextPosition( m_entity );
    newPos.y += m_entity.getSpriteSize().y;

    float newPosRight = newPos.x + m_entity.getSpriteSize().x; //To check the right bound of the player


    if ( !tileSolid ( m_level, newPos ) && !tileSolid ( m_level, { newPosRight, newPos.y } ) )
    {
        m_entity.setIfOnGround( false );
    }
}

void
Effected_By_Gravity :: applyGravity    ()
{
    sf::Vector2f newPos = getNextPosition( m_entity );
    newPos.y += m_entity.getSpriteSize().y;
    float newPosRight = newPos.x + m_entity.getSpriteSize().x; //To check the right bound of the player

    if ( !m_entity.isOnGround() )
    {
        m_entity.changeVelocity( 0,  m_entity.getGravity() );

        if ( tileSolid( m_level, newPos ) || tileSolid ( m_level, { newPosRight, newPos.y } ) )
        {
            m_entity.resetYVelocity();
            m_entity.setIfOnGround( true );
        }
    }
}

} //Namespace Component
