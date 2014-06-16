#include "particlesystem.h"

using namespace std;

ParticleSystem::ParticleSystem(int screen_width, int screen_height) {
    this->screen_width = screen_width;
    this->screen_height = screen_height;
    srand(time(NULL));
    for(int i=0; i<50; i++) {
        Particle particle(rand() % screen_width, 0, rand() % 1000);
        particles.push_back(particle);
    }
}

ParticleSystem::ParticleSystem() {

}

void ParticleSystem::update_all(int delay) {
    for(int i=0; i<particles.size(); i++) {
        particles.at(i).update(delay);
        particles.at(i).updates++;
        if(particles.at(i).updates > particles.at(i).lifetime) {
//            particles.erase(particles.begin() + i);
//            Particle particle(rand() % screen_width, 0, rand() % 1000);
//            particles.push_back(particle);
        }
    }
}
