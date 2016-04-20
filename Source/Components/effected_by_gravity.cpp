#include "effected_by_gravity.h"

#include "tile_map_component_funcs.h" //tileSolid(), getNextPosition()

namespace Component
{

Effected_By_Gravity :: Effected_By_Gravity ( Entity& entity, const Level& level, Window& window, GravityParticles& particles )
:   m_entity            ( entity )
,   m_level             ( level  )
,   m_window            ( window )
,   m_landingParticles  ( particles )
{

}

void
Effected_By_Gravity :: update ( const float dt )
{
    checkIfOnGround ();
    applyGravity    ();
}

void
Effected_By_Gravity :: checkIfOnGround ()
{
    sf::Vector2f newPos = getNextPosition( m_entity );  //Gets the position of the underneath the player (world Coordinates)
    newPos.y += m_entity.getSpriteSize().y;
    float newPosRight = newPos.x + m_entity.getSpriteSize().x; //To check the right bound of the player

    if ( !tileSolid ( m_level, newPos ) && !tileSolid ( m_level, { newPosRight, newPos.y } ) )
    {
        m_entity.setIfOnGround( false );
        //If the player is not on the ground, it updates it's "am i on the ground" boolean
    }
}

void
Effected_By_Gravity :: applyGravity    ( )
{
    sf::Vector2f newPos = getNextPosition( m_entity );          //Gets the position of the underneath the player (world Coordinates)
    newPos.y += m_entity.getSpriteSize().y;
    float newPosRight = newPos.x + m_entity.getSpriteSize().x; //To check the right bound of the player, an X-Coordinate

    if ( !m_entity.isOnGround() )
    {
        m_entity.changeVelocity( 0,  m_entity.getGravity() );   //If the player isn't on the ground, its velocity "increases" (dumb opengl coordinate systems amiright)

        //If the player lands on a solid tile
        if ( tileSolid( m_level, newPos ) || tileSolid ( m_level, { newPosRight, newPos.y } ) )
        {
            //Calculate the "intensity" of the fall
            int fallIntensity = -m_entity.getVelocity().y / 3;

            //Add particles to the landing site
            m_landingParticles.addParticles( abs ( fallIntensity * 10 ),      //Particles added is proportinal to the fall intensity
                                            { ( newPos.x + newPosRight ) / 2    //X position, between the 2 bottom edge vertex of player,
                                            ,   newPos.y - m_entity.getSpriteSize().y / 5},   //Y position -size... so particles don't insta stuck in the ground
                                            {0, (float)fallIntensity * 2 }            //Direction
                                            );

            m_window.turnOnShake( fallIntensity, 0.1 );

            m_entity.resetYVelocity();          // Stops the Y velocity if the player is on the ground/ touching a solid tile on either side of it's bottom
            m_entity.setIfOnGround( true );     // touching a solid tile on either side of it's bottom
        }
    }
}

} //Namespace Component
