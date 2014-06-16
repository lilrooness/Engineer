#include "newtentity.h"

NewtEntity::NewtEntity(float xpos, float ypos) {
    this->xpos = xpos;
    this->ypos = ypos;

    this->xacc = 0;
    this->yacc = 0;

    this->xvel = 0;
    this->yvel = 0;

    this->mass = 1;
}

void NewtEntity::applyForce(float x, float y) {
    xacc += x;
    yacc += y;
}

void NewtEntity::update(int delay) {
    xvel += xacc / mass;
    yvel += yacc / mass;

    xacc = 0;
    yacc = 0;

    xpos += xvel * delay;
    ypos += yvel * delay;

}
