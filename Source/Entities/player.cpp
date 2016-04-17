#include "player.h"

#include "tile_info.h"

#include "tile_collidable.h"
#include "effected_by_gravity.h"

Player :: Player(  const Level& level, const Game& game )
:   Entity  ( { Tile::TILE_SIZE / 2, Tile::TILE_SIZE * 1.5 }, { 1000, 50 }, game.getTexture ( Texture_Name::Player )  )
,   m_level ( level )
{
    updateTilePosition();

    addComponent( std::make_unique<Component::Tile_Collidable>
                ( *this, m_level ) );

    addComponent( std::make_unique<Component::Effected_By_Gravity>
                ( *this, m_level ) );
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

}
