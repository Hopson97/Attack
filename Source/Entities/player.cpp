#include "player.h"

#include "tile_info.h"

#include "tile_collidable.h"
#include "effected_by_gravity.h"

Player :: Player(  const Level& level, const Game& game )
:   Entity  ( { Tile::TILE_SIZE / 2, Tile::TILE_SIZE * 1.5 }, { 1000, 50 }, game.getTexture ( Texture_Name::Player )  )
,   m_level ( level )
{
    updateTilePosition();
}

void
Player :: input ( const float dt )
{
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) && isOnGround() )
    {
        changeVelocity (  0, -m_jumpSpeed * dt );
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
    {
        changeVelocity ( -m_walkSpeed * dt, 0 );
    }
    if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
    {
        changeVelocity ( m_walkSpeed * dt, 0 );
    }
}

void
Player :: uniqueUpdate ( const float dt )
{
    Tile_Collidable c ( *this, m_level );
    Effected_By_Gravity e( *this, m_level );

    c.update();
    e.update();
}
