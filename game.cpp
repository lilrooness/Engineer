#include "game.h"

using namespace std;

Game::Game() {
    map.loadBinaryMap("levels/map.bin");
    this->system = ParticleSystem(640, 480);
    this->player = Player(5, 5, 3);
    this->dims = map.loadBinaryMap("levels/map.bin");
}

void Game::tick(int delay) {
    system.update_all(delay);

    while(commands.size() > 0) {
        commands.front()->execute(&player);
        delete commands.front();
        commands.pop();
    }
}
