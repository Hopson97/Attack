#ifndef TILE_COLLIDABLE_H
#define TILE_COLLIDABLE_H

#include "entity.h"
#include "level.h"

#include "component_base.h"

#include "Particles/gravity_particles.h"

namespace Component
{

class Tile_Collidable : public Component_Base
{
    public:
        Tile_Collidable( Entity& enity, const Level& level, Gravity_Particles* dirt = nullptr );

        void
        update ( const float dt ) override;

    private:
        void
        checkLeftCollide    ( const float dt );

        void
        checkRightCollide   ( const float dt );

        void
        checkUpCollide      ( const float dt );

        void
        checkXTile          ( const sf::Vector2f& newPos );

        void
        checkYTile          ( const sf::Vector2f& newPos );

        void
        addParticles        ();

    private:
        Entity&         m_entity;
        const Level&    m_level;

        Gravity_Particles*   m_dirtParticles;
};

} //Namespace Component

#endif // TILE_COLLIDABLE_H
