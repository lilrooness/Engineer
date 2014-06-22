#include "game.h"

using namespace std;

Game::Game() {
    map.loadBinaryMap("levels/map.bin");
    this->system = ParticleSystem(640, 480);
    this->player = Player(5, 5, 3);
    this->camera = Entity(player.x - 5, player.y - 4, -1);
    this->dims = map.loadBinaryMap("levels/map.bin");
    cout<<dims.cols<<endl;
}

void Game::tick(int delay) {
    system.update_all(delay);

    while(commands.size() > 0) {
        commands.front()->execute(&player);
        delete commands.front();
        commands.pop();
    }

    camera.x = player.x - 5;
    camera.y = player.y - 4;
}
