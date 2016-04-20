#ifndef LEVEL_H
#define LEVEL_H

///Where the tile map code stuff will go I guess

#include <vector>
//#include <map>

#include "grass.h"

enum class Model
{
    Grass
,   Dirt
};

class Level
{
    friend class Map_Loader;

    using TilePtr = std::unique_ptr<Tile::Tile_Base>;

    public:
        Level ( const Game* game );

        void
        update  ( const float dt );

        void
        draw    ( sf::RenderWindow& window, const sf::Vector2i& playerPos );

        const TilePtr&
        getTileAt ( const int x, const int y ) const;

        const TilePtr&
        getTileAt ( const sf::Vector2i& tilePosition ) const;

        void
        getScreenBounds(  int& xStart, int& yStart,
                          int& xEnd,   int& yEnd,
                          const sf::Vector2i& playerTilePos ) const;

        const int
        getGravity      () const;

    private:
        std::vector<TilePtr> m_tiles;

        std::map<Model, Tile_Model> m_models;

        int m_mapHeight;
        int m_mapWidth;

        constexpr static int m_GRAVITY = 2000;
};

#endif // LEVEL_H
