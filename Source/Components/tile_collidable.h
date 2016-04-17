#ifndef TILE_COLLIDABLE_H
#define TILE_COLLIDABLE_H

#include "entity.h"
#include "level.h"

class Tile_Collidable
{
    public:
        Tile_Collidable( Entity& enity, const Level& level );

        void
        update ();

    private:
        void
        checkLeftCollide    ();

        void
        checkRightCollide   ();

        void
        checkUpCollide      ();

        void
        checkXTile          ( const sf::Vector2f& newPos );

        const bool
        tileSolid           ( const sf::Vector2f& newPos  ) const;

        const sf::Vector2f
        getNextPosition() const;

    private:
        Entity&         m_entity;
        const Level&    m_level;
};

#endif // TILE_COLLIDABLE_H
