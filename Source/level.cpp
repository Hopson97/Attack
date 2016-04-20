#include "level.h"

#include "map_loader.h"
#include "tile_info.h"

#include <string>

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
Level :: draw    ( sf::RenderWindow& window, const sf::Vector2i& playerPos )
{
    int xStart, yStart, xEnd, yEnd;
    getScreenBounds( xStart, yStart, xEnd, yEnd, playerPos );

    for ( int y = yStart ; y < yEnd ; y++ )
    {
        for ( int x = xStart ; x < xEnd ; x++ )
        {
            getTileAt( x, y )->draw ( window );
        }
    }
}

void
Level :: getScreenBounds(  int& xStart, int& yStart,
                           int& xEnd,   int& yEnd,
                           const sf::Vector2i& playerTilePos ) const
{
    constexpr static int tilesX = (winInfo::WIDTH / Tile::TILE_SIZE );

    constexpr static int tilesY = (winInfo::WIDTH / Tile::TILE_SIZE );

    xStart = playerTilePos.x - tilesX;
    yStart = playerTilePos.y - tilesY;

    if ( xStart < 0 ) xStart = 0;
    if ( yStart < 0 ) yStart = 0;

    xEnd = playerTilePos.x + tilesX;
    yEnd = playerTilePos.y + tilesY;

    if ( xEnd > m_mapWidth  - 1 ) xEnd = m_mapWidth;
    if ( yEnd > m_mapHeight - 1 ) yEnd = m_mapHeight;
}

const TilePtr&
Level :: getTileAt ( const int x, const int y ) const
{
    return getTileAt( { x, y } );
}

const TilePtr&
Level :: getTileAt ( const sf::Vector2i& tilePosition ) const
{
    if ( (unsigned)tilePosition.y * m_mapWidth + tilePosition.x > m_tiles.size() - 1 )
    {
        std::string xLoc = std::to_string( tilePosition.x );
        std::string yLoc = std::to_string( tilePosition.y );

        std::string coords = "tile map location (" + xLoc + "," + yLoc + ")";

        std::string xLocMax = std::to_string( m_mapWidth  );
        std::string yLocMax = std::to_string( m_mapHeight );

        std::string coordsMax = "(" + xLocMax + "," + yLocMax + ")";

        throw std::runtime_error ( "Tried to access the Tile at: " + coords + ", where the maximum size is " + coordsMax + ".");
    }
    else
    {
        return m_tiles.at ( tilePosition.y * m_mapWidth + tilePosition.x );
    }
}
