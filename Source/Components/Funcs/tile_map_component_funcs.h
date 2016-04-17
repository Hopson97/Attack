#ifndef TILE_MAP_COMPONENT_FUNCS_H
#define TILE_MAP_COMPONENT_FUNCS_H

#include "entity.h"
#include "level.h"

const bool
tileSolid           ( const Level& level, const sf::Vector2f& newPos );

const sf::Vector2f
getNextPosition     ( const Entity& entity );

#endif // TILE_MAP_COMPONENT_FUNCS_H
