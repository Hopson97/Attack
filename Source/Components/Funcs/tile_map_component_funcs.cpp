#include "tile_map_component_funcs.h"

#include "tile_info.h"

#include <iostream>

namespace Component
{

//Tells where the tile position in the area given is solid or not
const bool
tileSolid ( const Level& level, const sf::Vector2f& newPos )
{
    return level.getTileAt( newPos.x / Tile::TILE_SIZE,
                            newPos.y / Tile::TILE_SIZE
                          ) ->m_isSolid;
}

//Predicts the next position of the entity
const sf::Vector2f
getNextPosition ( const Entity& entity, const float dt )
{
    sf::Vector2f newPos;    // The new tile map position of the player
    newPos.x = (entity.getSpritePosition().x ) + entity.getVelocity().x * dt ;
    newPos.y = (entity.getSpritePosition().y ) + entity.getVelocity().y * dt;

    return newPos;
}

} //Namespace Component
