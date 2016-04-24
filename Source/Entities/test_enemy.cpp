#include "test_enemy.h"

#include "points_towards_direction.h"
#include "tile_collidable.h"

#include "math_funcs.h"
#include <iostream>

static int count = 0;

Test_Enemy :: Test_Enemy( const sf::Vector2f& position, const Game& game, const Level& level, const Player& player,
                         Gravity_Particles& blood, std::vector<BulletPtr>& bullets )
:   Entity      ( { 40, 40 }, position, game.getTexture(Texture_Name::Eye_Enemy), level )
,   m_player    ( player )
,   m_blood     ( blood )
,   m_bullets   ( bullets )
{
    addComponent( std::make_unique<Component::Points_Towards_Direction>
                ( *this ) );

    addComponent( std::make_unique<Component::Tile_Collidable>
                ( *this, level, true, true ) );

    centerSpriteOrigin();
}

void
Test_Enemy :: uniqueUpdate( const float dt )
{
    float dy, dx;

    Math::getDyDx( getSpritePosition(), m_player.getSpritePosition(), dx, dy );

    float angle = Math::getRotInDeg( dx, dy );
    angle = Math::toRads( angle );

    float xSpeed = (float) cos ( angle ) * m_accleration;
    float ySpeed = (float) sin ( angle ) * m_accleration;

    setVelocity( getVelocity().x + xSpeed, getVelocity().y + ySpeed );

    for ( auto& bullet : m_bullets )
    {
        if ( intersects( *bullet ) )
        {
            std::cout << "Number dead: " << ++count << std::endl;
            setAlive( false );
            m_blood.addParticles( 25, getSpritePosition(), { 0, 0} );
        }
    }
}
