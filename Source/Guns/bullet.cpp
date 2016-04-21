#include "bullet.h"

#include "effected_by_gravity.h"
#include "tile_collidable.h"

#include "math_funcs.h"
#include "friction.h"

#include <iostream>

Bullet :: Bullet ( const Level& level, const Game& game, const Player& player, Window& window, const sf::Vector2f& targetLocation, GravityParticles& particles )
:   Entity ( {12,12}, player.getSpritePosition(), game.getTexture(Texture_Name::Bullet), level )
{

    addComponent( std::make_unique<Component::Tile_Collidable>
                ( *this, level, &particles ) );

    addComponent( std::make_unique<Component::Effected_By_Gravity>
                ( *this, level, window, particles ) );

    //addComponent( std::make_unique<Component::Friction>
    //            ( *this, level ) );

    float dx = getSpritePosition().x - targetLocation.x;
    float dy = getSpritePosition().y - targetLocation.y;

    float angle = Math::getRotInDeg( dx, dy );
    angle = Math::toRads( angle );

    float xSpeed = (float) cos ( angle ) * speed;
    float ySpeed = (float) sin ( angle ) * speed;

    setVelocity( xSpeed, ySpeed );
}

void
Bullet :: uniqueUpdate ( const float dt )
{
    this->moveSprite(dt);
}

bool
Bullet :: isFallen    () const
{
    return m_eraseClock.getElapsedTime().asSeconds() >= m_lifetime;
}
