#ifndef MAP_LOADER_H
#define MAP_LOADER_H

#include "air.h"
#include "grass.h"
#include "level.h"
#include "tile_model.h"

#include <map>


class Map_Loader
{
    public:
        Map_Loader  (){}

        void
        loadMap     ( Level* level, const std::string& filePath,
                      std::map<Model, Tile_Model>& models );

    private:
        void
        switchChar  ( const char c );

        Level* m_level;

        int currY;
        int currX;

        std::map<Model, Tile_Model>* m_models;

};

#endif // MAP_LOADER_H
