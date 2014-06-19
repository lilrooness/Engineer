#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{
public:
    Player(int x, int y, int sprite_id);
    Player();
};

#endif // PLAYER_H
