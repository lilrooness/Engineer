#include "movecommand.h"

#include <iostream>

using namespace std;

MoveCommand::MoveCommand(char dir) : dir(dir) {
    //ctor
}

MoveCommand::~MoveCommand() {
    //dtor
}

void MoveCommand::execute(Entity *e) {
        switch(dir) {
        case 'w': {
            e->y -= 1;
        }break;
        case 'a': {
            e->x -= 1;
        }break;
        case 's': {
            e->y += 1;
        }break;
        case 'd': {
            e->x += 1;
        }break;
    }

    cout<<"x: "<<e->x<<" y: "<<e->y<<endl;
}

void MoveCommand::undo(Entity *e) {

}
