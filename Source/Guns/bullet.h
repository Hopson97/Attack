#ifndef BULLET_H
#define BULLET_H

#include "game.h"
#include "entity.h"
#include "level.h"
#include "player.h"
#include "window.h"

class Bullet    :   public Entity
{
    public:
        Bullet      ( const Level& level, const Game& game, const Player& player, Window& window, const sf::Vector2f& targetLocation );

    private:
        void
        uniqueUpdate ( const float dt ) override;

        const int speed = 150;

};

#endif // BULLET_H
