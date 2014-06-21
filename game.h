#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <queue>

#include "subject.h"
#include "particlesystem.h"
#include "map.h"
#include "player.h"
#include "command.h"
#include "movecommand.h"

class Game : public Subject {
public:
    Game();
    ParticleSystem system;
    void tick(int delay);
    Map map;
    Player player;

    std::queue<Command*> commands;
    map_dims dims;

};

#endif // GAME_H
