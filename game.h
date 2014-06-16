#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "subject.h"
#include "particlesystem.h"

class Game : public Subject {
public:
    Game();
    ParticleSystem system;
    void tick(int delay);
};

#endif // GAME_H
