#ifndef TILE_COLLIDABLE_H
#define TILE_COLLIDABLE_H

#include "entity.h"
#include "level.h"

#include "component_base.h"

namespace Component
{

class Tile_Collidable : public Component_Base
{
    public:
        Tile_Collidable( Entity& enity, const Level& level );

        void
        update ( const float dt ) override;

    private:
        void
        checkLeftCollide    ();

        void
        checkRightCollide   ();

        void
        checkUpCollide      ();

        void
        checkXTile          ( const sf::Vector2f& newPos );

    private:
        Entity&         m_entity;
        const Level&    m_level;
};

} //Namespace Component

#endif // TILE_COLLIDABLE_H
