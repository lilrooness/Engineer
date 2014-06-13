#include "map.h"

using namespace std;

Map::Map() {
    //pre calculate ID tilesheet positions
    int id_map_size = 16*16;
    this->id_map = new grid_point[id_map_size];
    for(int i=0; i<id_map_size; i++) {
        grid_point gp;
        gp.y = i / 16;
        gp.x = i - gp.y * 16;
        id_map[i] = gp;
    }
}

map_dims Map::loadBinaryMap(string filename) {

    ifstream in;
    in.open(filename.c_str(), ios::in | ios::binary);
    map_dims dims;
    char header[4];
    in.read(header, 4);
    char dimensions[2];

    if(in.is_open()) {
        in.read(dimensions , 2);
    }
    dims.rows = dimensions[0];
    dims.cols = dimensions[1];

    char *data = new char[dims.rows * dims.cols];
    in.read(data, dims.rows * dims.cols);

    unsigned_map = new unsigned char*[dims.rows];
    for(int y=0; y<dims.rows; y++) {
        unsigned_map[y] = new unsigned char[dims.cols];
        for(int x=0; x<dims.cols; x++) {
            unsigned_map[y][x] = (unsigned char)data[x + dims.cols*y];
        }
    }
    delete [] data;
    return dims;
}
