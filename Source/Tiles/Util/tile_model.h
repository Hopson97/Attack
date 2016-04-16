#ifndef TILE_MODEL_H
#define TILE_MODEL_H

#include "tile_info.h"

class Tile_Model
{
    public:

        void
        setUp ( const sf::Texture& texture );

        void
        setPosition ( const int x, const int y );

        void
        draw        ( sf::RenderWindow& window );

    private:
        sf::RectangleShape m_tile;

        bool hasSetUp = false; //Exists because std::map is being awkward
};

#endif // TILE_MODEL_H
