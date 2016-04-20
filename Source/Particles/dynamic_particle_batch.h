#ifndef DYNAMIC_PARTICLE_BATCH_H
#define DYNAMIC_PARTICLE_BATCH_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "level.h"
#include "rand.h"

class GravityParticles : public sf::Drawable, public sf::Transformable
{
    public:
        GravityParticles( const sf::Color& colour, const Level& level );

        void
        addParticles        ( const int count, const sf::Vector2f& location, const sf::Vector2f& direction );

        void
        update              ( const float dt );

        void
        draw                ( sf::RenderTarget& window, sf::RenderStates states = sf::RenderStates::Default ) const override;

    private:
        //Particle class
        class Particle
        {
        public:
            Particle        ( const Level& level, const sf::Vector2f& direction, sf::Vertex& v );

            const bool
            onGround        ( const sf::Vertex& vertex );

            const sf::Vector2f&
            getVelocity     () const;

        private:
            const bool
            isOnSolidTile   ( const sf::Vertex& vertex );

            const Level* m_level;
            sf::Vector2f m_velocity;
        };
        sf::VertexArray         m_vertices;
        sf::Color               m_colour;
        std::vector<Particle>   m_particles;

        const Level&            m_level;
};

#endif // DYNAMIC_PARTICLE_BATCH_H