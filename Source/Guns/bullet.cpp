#include "bullet.h"

#include "effected_by_gravity.h"
#include "tile_collidable.h"

#include "math_funcs.h"

Bullet :: Bullet( const Level& level, const Game& game, const Player& player, Window& window, const sf::Vector2f& targetLocation )
:   Entity ( {5,5}, player.getSpritePosition(), game.getTexture(Texture_Name::Player) )
{
    addComponent( std::make_unique<Component::Tile_Collidable>
                ( *this, level ) );

    addComponent( std::make_unique<Component::Effected_By_Gravity>
                ( *this, level, window ) );

    int dx = getSpritePosition().x - targetLocation.x;
    int dy = getSpritePosition().y - targetLocation.y;

    setRotation( Math::getRotInRad( dx, dy ) );

    float rotInRad = Math::toRads( getRotation() + 90 );

    int xVel = cos ( rotInRad * speed );
}

void
Bullet :: uniqueUpdate ( const float dt )
{

}
