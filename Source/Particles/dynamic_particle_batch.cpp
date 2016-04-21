#include "dynamic_particle_batch.h"

#include <iostream>

GravityParticles :: GravityParticles( const sf::Color& colour, const Level& level )
:   m_colour        ( colour )
,   m_level         ( level )
{ }

void
GravityParticles :: addParticles ( const int count, const sf::Vector2f& location, const sf::Vector2f& direction )
{
    for ( int i = 0 ; i < count ; i ++ )
    {
        m_vertices.append           ( sf::Vertex( location, m_colour) );
        m_particles.emplace_back    ( m_level, direction );
    }
}

void
GravityParticles :: update ( const float dt )
{
    for ( size_t i = 0 ; i < m_particles.size() ; i++ )
    {
        //Get the vertex and particle at i index for shorthand
        Particle& p     = m_particles[i];
        sf::Vertex& v    = m_vertices[i];

        v.position += p.getVelocity() * dt;

        if ( p.onGround( v, dt ) )
        {
            //m_particles.erase( m_particles.begin() + i );
        }
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
GravityParticles :: Particle :: Particle ( const Level& level, const sf::Vector2f& direction )
:   m_level  ( &level )
{
    const float dy = direction.y;
    const float dx = direction.x;

    //If there is "no direction", then we give it a random direction
    if ( dx == 0 )
        while ( m_velocity.x == 0)
            m_velocity.x = random::num( -2, 2 );
    if ( dy == 0 )
        while ( m_velocity.y == 0)
            m_velocity.y = random::num( -2, 2 );

    //We use ternary operators here because the function random::num takes in a low and then a high number
    //If the number is positive/ negative, it would otherwise always return a positive number
    while ( m_velocity.x == 0)
        m_velocity.x = random::num( dx > 0 ? 1  : dx,
                                    dx > 0 ? dx : -1 );

    while ( m_velocity.y == 0)
        m_velocity.y = random::num( dy > 0 ? 1  : dy,
                                    dy > 0 ? dy : -1 );
    //Multiply by 50 because it is too slow otherwise (thanks to delta time )
    m_velocity.x *= 50;
    m_velocity.y *= 50;
}


//Particle :: onGround
const bool
GravityParticles :: Particle :: onGround( const sf::Vertex& vertex, const float dt )
{
    if( !isOnSolidTile(vertex) )
    {
        m_velocity.y += m_level->getGravity() * dt;
        return false;
    }
    else if ( isOnSolidTile(vertex) )
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

    if ( tilePositionX < 0 ) tilePositionX = 0;
    if ( tilePositionY < 0 ) tilePositionY = 0;


    return m_level->getTileAt( tilePositionX, tilePositionY )->m_isSolid;
}

//Particle :: getVecloity
const sf::Vector2f&
GravityParticles :: Particle :: getVelocity () const
{
    return m_velocity;
}
