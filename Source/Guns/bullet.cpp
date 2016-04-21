#include "bullet.h"

#include "effected_by_gravity.h"
#include "tile_collidable.h"

#include "math_funcs.h"
#include "friction.h"

#include <iostream>

Bullet :: Bullet( const Level& level, const Game& game, const Player& player, Window& window, const sf::Vector2f& targetLocation )
:   Entity ( {12,12}, player.getSpritePosition(), game.getTexture(Texture_Name::Bullet), level )
{

    addComponent( std::make_unique<Component::Tile_Collidable>
                ( *this, level ) );

    //addComponent( std::make_unique<Component::Effected_By_Gravity>
    //            ( *this, level, window ) );

    //addComponent( std::make_unique<Component::Friction>
    //            ( *this, level ) );

    float dx = getSpritePosition().x - targetLocation.x + (targetLocation.x/4) + 32;
    float dy = getSpritePosition().y - targetLocation.y - (targetLocation.y/4);

    sf::Vector2i mouseCoordinates = sf::Mouse::getPosition(window.get());
    directionVector = {mouseCoordinates.x - dx, mouseCoordinates.y - dy};
    this->setVelocity(directionVector.x / 3, directionVector.y / 3);

    std::cout << "Direction Vector: " << directionVector.x << ", " << directionVector.y << std::endl;

    //std::cout << "ORIG POS "    << getSpritePosition().x    << " " << getSpritePosition().y << std::endl;
    //std::cout << "NEW POS "     << targetLocation.x         << " " << targetLocation.y      << std::endl;
    //std::cout << "DIFF "        << getSpritePosition().x - targetLocation.x << " " << getSpritePosition().y - targetLocation.y << std::endl << std::endl;

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
