#include "game.h"

using namespace std;

Game::Game() {
    this->system = ParticleSystem(640, 480);
    for(int i=0; i<system.particles.size(); i++) {
        cout<<system.particles.at(i).xpos<<endl;
    }
}

void Game::tick(int delay) {
    system.update_all(delay);
}
