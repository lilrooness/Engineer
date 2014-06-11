#include "map.h"

using namespace std;

Map::Map() {

}

map_dims Map::loadMap(const char* filename) {
    int lines = 0;
    string line;
    ifstream mapFile;
    mapFile.open(filename);

    while(mapFile.good()){
        getline(mapFile, line);
        lines++;
    }

    mapFile.close();
    mapFile.open(filename);
    int counter = 0;
    vector<string> lineArray(lines);

    while(mapFile.good()){
        getline(mapFile, lineArray[counter++]);
    }

    mapFile.close();
    int length = lineArray[0].size();

    //create new 2D int array
    map = new int *[lines - 1];

    for(int i=0; i<lines - 1; i++){
        map[i] = new int[length];
    }

    for(int i=0; i<lines - 1; i++){
        for(int j=0; j<length; j++){
            map[i][j] = lineArray[i][j] - '0';
        }
    }

    map_dims dim;
    dim.rows = lines - 1;
    dim.cols = length;

    return dim;
}
