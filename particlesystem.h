#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <vector>
#include <time.h>
#include <cstdlib>
#include <iostream>

#include "particle.h"

class ParticleSystem
{
public:
    ParticleSystem(int screen_width, int screen_height);
    ParticleSystem();
    std::vector<Particle> particles;
    void update_all(int delay);
    int screen_width, screen_height;
};

#endif // PARTICLESYSTEM_H
