#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "subject.h"
#include "particlesystem.h"
#include "map.h"

class Game : public Subject {
public:
    Game();
    ParticleSystem system;
    void tick(int delay);
    Map map;
};

#endif // GAME_H
