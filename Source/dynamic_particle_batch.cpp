#include "dynamic_particle_batch.h"

#include <iostream>

GravityParticles :: GravityParticles( const sf::Color& colour, const Level& level )
:   m_colour        ( colour )
,   m_level         ( level )
{
    //ctor
}

void
GravityParticles :: addParticles ( const int count, const sf::Vector2f& location )
{
    for ( int i = 0 ; i < count ; i ++ )
    {
        m_particles.emplace_back    ( m_level );
        m_vertices.append           ( sf::Vertex( location, m_colour) );
    }
}

void
GravityParticles :: update ( const float dt )
{
    for ( size_t i = 0 ; i < m_particles.size() ; i++ )
    {
        //Get the vertex and particle at i index
        Particle& p     = m_particles[i];
        sf::Vertex& v   = m_vertices[i];

        v.position += p.getVelocity();

        p.onGround( v );

    }
}

void
GravityParticles :: draw  ( sf::RenderTarget& window, sf::RenderStates states ) const
{
    states.transform *= getTransform();
    states.texture = NULL;
    window.draw(m_vertices, states);
}

///PARTICLE METHODS AND STUFF BELOW HERE
//Particle constructor
GravityParticles :: Particle :: Particle ( const Level& level )
:   m_level ( level )
{
    while ( m_velocity.x == 0)
        m_velocity.x = random::num( -3, 3 );

    while ( m_velocity.y == 0)
        m_velocity.y = random::num( -3, 3 );
}

//Particle :: onGround
const bool
GravityParticles :: Particle :: onGround( const sf::Vertex& vertex )
{
    if( !isOnSolidTile( vertex ) )
    {
        m_velocity.y += 0.2;
        return false;
    }
    else if ( isOnSolidTile( vertex ) )
    {
        m_velocity.y = 0;
        m_velocity.x = 0;

        return true;
    }
    return false;
}

//isOnSolidTile for Particle
const bool
GravityParticles :: Particle :: isOnSolidTile( const sf::Vertex& vertex )
{
    int tilePositionX = vertex.position.x / Tile::TILE_SIZE;
    int tilePositionY = vertex.position.y / Tile::TILE_SIZE;


    return m_level.getTileAt( tilePositionX, tilePositionY )->m_isSolid;
}

//Particle :: getVecloity
const sf::Vector2f&
GravityParticles :: Particle :: getVelocity () const
{
    return m_velocity;
}
