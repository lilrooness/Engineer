#ifndef MAP_H
#define MAP_H

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

struct {
    int rows, cols;
}typedef map_dims;

class Map
{
public:
    Map();
    map_dims loadMap(const char *filename);
    int **map;
};

#endif // MAP_H
