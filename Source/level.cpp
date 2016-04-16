#include "level.h"

#include "map_loader.h"

typedef std::unique_ptr<Tile::Tile_Base>  TilePtr;

Level :: Level( const Game* game )
{
    m_models[ Model::Grass ].setUp( game->getTexture( Texture_Name::Grass ) );
    m_models[ Model::Dirt  ].setUp( game->getTexture( Texture_Name::Dirt  ) );

    Map_Loader loader;

    loader.loadMap( this, "Res/Maps/test.helimap", m_models );
}

void
Level :: update  ( const float dt )
{
    for ( auto& tile : m_tiles )
    {
        tile->update( dt );
    }
}

void
Level :: draw    ( sf::RenderWindow& window )
{
    for ( auto& tile : m_tiles )
    {
        tile->draw( window );
    }
}

const TilePtr&
Level :: getTileAt ( const int x, const int y ) const
{
    return getTileAt( { x, y } );
}

const TilePtr&
Level :: getTileAt ( const sf::Vector2i& tilePosition ) const
{
    return m_tiles.at ( tilePosition.y * m_mapWidth + tilePosition.x );
}
