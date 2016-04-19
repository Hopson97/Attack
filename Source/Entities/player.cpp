#include "player.h"

#include "tile_info.h"

#include "tile_collidable.h"
#include "effected_by_gravity.h"

Player :: Player(  const Level& level, const Game& game, Window& window )
:   Entity  ( { Tile::TILE_SIZE / 2, Tile::TILE_SIZE * 1.5 }, { 1000, 50 }, game.getTexture ( Texture_Name::Player )  )
,   m_level     ( level )
,   m_window    ( window )
{
    updateTilePosition();

    addComponent( std::make_unique<Component::Tile_Collidable>
                ( *this, m_level ) );

    addComponent( std::make_unique<Component::Effected_By_Gravity>
                ( *this, m_level, m_window ) );

    //Set up animations
    const float m_time = 0.03; //Time between animation frames
    const int frameHeight = 70; //The frames are of equal size, so we can use these constants
    const int frameWidth  = 30;

    sf::IntRect standing = {0,              0, frameWidth, frameHeight };
    sf::IntRect walk1    = {frameWidth,     0, frameWidth, frameHeight };
    sf::IntRect walk2    = {frameWidth * 2, 0, frameWidth, frameHeight };

    m_walkAnim.addFrame( { standing, m_time } );
    m_walkAnim.addFrame( { walk1, m_time    } );
    m_walkAnim.addFrame( { standing, m_time } );
    m_walkAnim.addFrame( { walk2, m_time    } );

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
    if ( isMoving() && isOnGround() )
    {
        setTextureRect( m_walkAnim.currentFrame( dt ) );
    }
    else
    {   //The "standing" texture rectangle of the players sprite sheet
        setTextureRect({0, 0, 30, 70 });
    }
}
