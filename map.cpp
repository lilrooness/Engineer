#include "map.h"

using namespace std;

Map::Map() {

}

map_dims Map::loadMap(const char *filename) {
    ifstream in;
    vector<string> lines;
    in.open(filename);
    string line;
    map_dims dims;

    if(!in.is_open()) {
        cout<<"Could not open level file: "<<filename<<endl;
        return dims;
    }

    while(getline(in, line)) {;
        lines.push_back(line);
    }

    int rows = lines.size();
    int cols = lines.at(0).size();

    dims.cols = cols;
    dims.rows = rows;

    this->map = new int*[rows];

    for(int i=0; i<rows; i++) {
        map[i] = new int[cols];
        for(int j=0; j<cols; j++) {
            map[i][j] = lines.at(i).at(j) - '0';
        }
    }

    return dims;

}
