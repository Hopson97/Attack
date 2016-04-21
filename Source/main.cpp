#include "game.h"

/**

To do:
    -> Both the Entity and Particle class have the OOB collision detection.
        So we need something to avoid the DRY here!

    -> Serious need of refactoring needed in the "Gravity Particles" class!

    ->  Glitch, particles appear inside tiles when bullets hit them




*/

int main()
{
    srand (time(NULL));
    Game game;
    game.runLoop();
    return 0;
}
