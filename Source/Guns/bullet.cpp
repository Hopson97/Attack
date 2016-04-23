#include "bullet.h"

#include "effected_by_gravity.h"
#include "tile_collidable.h"

#include "math_funcs.h"
#include "friction.h"

#include "rand.h"

#include <iostream>

Bullet :: Bullet ( const Level& level, const Game& game, const Player& player, Window& window, const sf::Vector2f& targetLocation, Gravity_Particles& particles )
:   Entity ( {12,12}, player.getSpritePosition(), game.getTexture(Texture_Name::Bullet), level )
{

    addComponent( std::make_unique<Component::Tile_Collidable>
                ( *this, level, &particles ) );

    addComponent( std::make_unique<Component::Effected_By_Gravity>
                ( *this, level, window, particles ) );

    float dx = getSpritePosition().x - targetLocation.x;
    float dy = getSpritePosition().y - targetLocation.y;

    float angle = Math::getRotInDeg( dx, dy );
    angle = Math::toRads( angle );

    float xSpeed = (float) cos ( angle ) * speed;
    float ySpeed = (float) sin ( angle ) * speed;

    int randDirRange = 50;

    xSpeed = random::numf( xSpeed - randDirRange, xSpeed + randDirRange );
    ySpeed = random::numf( ySpeed - randDirRange, ySpeed + randDirRange );

    setVelocity( xSpeed, ySpeed );
}

void
Bullet :: uniqueUpdate ( const float dt )
{

}

bool
Bullet :: isFallen    () const
{
    return ( getVelocity().x == 0 || getVelocity().y == 0 );
}
