#ifndef MAP_H
#define MAP_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#define TILE_GRATE_TL 1
#define TILE_GRATE_TM 2
#define TILE_GRATE_TR 3
#define TILE_GRATE_ML 4
#define TILE_GRATE_MM 5
#define TILE_GRATE_MR 6
#define TILE_GRATE_BL 7
#define TILE_GRATE_BM 8
#define TILE_GRATE_BR 9

typedef struct {
    int rows, cols;
}map_dims;

typedef struct {
    int x, y;
}grid_point;

class Map
{
public:
    Map();
    unsigned char **unsigned_map;
    map_dims loadBinaryMap(std::string map);
    grid_point *id_map;
};

#endif // MAP_H
