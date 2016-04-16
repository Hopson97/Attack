#include "air.h"

namespace Tile
{


Air::Air( const int xPos, const int yPos )
:   Tile_Base ( xPos, yPos )
{
    m_isSolid = false;
}

}
