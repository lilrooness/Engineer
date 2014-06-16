#ifndef PARTICLE_H
#define PARTICLE_H

#include "newtentity.h"

class Particle : public NewtEntity
{
public:
    Particle(int xpos, int ypos, int lifetime);
    int lifetime;
    int updates;
};

#endif // PARTICLE_H
