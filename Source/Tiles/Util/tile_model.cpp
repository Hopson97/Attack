#include "tile_model.h"

void
Tile_Model :: setUp ( const sf::Texture& texture )
{
    m_tile.setTexture   ( &texture );
    m_tile.setSize      (  Tile::TILE_RECT );
}

void
Tile_Model :: setPosition ( const int x, const int y )
{
    m_tile.setPosition( x, y );
}

void
Tile_Model :: draw ( sf::RenderWindow& window )
{
    window.draw ( m_tile );
}
