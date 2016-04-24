#ifndef WORLD_H
#define WORLD_H

#include "level.h"
#include "test_enemy.h"
#include "player.h"
#include "level.h"

class World
{
    public:
        World();

    protected:

    private:
        Level m_level;
};

#endif // WORLD_H
