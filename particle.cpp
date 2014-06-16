#include "particle.h"

Particle::Particle(int x, int y, int lifetime) : NewtEntity(x, y) {
    this->lifetime = lifetime;
}

