#include <iostream>
#include <SDL2/SDL.h>

#include "game.h"
#include "map.h"
#include "torchanimation.h"
#include "renderer.h"
#include "constants.h"

using namespace std;

int main(int argc, char *argv[]) {

    SDL_Init(SDL_INIT_VIDEO);

    int time_now = 0;
    int time_last = 0;
    int delay = time_now - time_last;

    bool isRunning = true;
    SDL_Event event;

    Game game;
    Renderer game_renderer;
    game_renderer.animations.push_back(new TorchAnimation(0, 0, LARGE_SPRITE_DIM, LARGE_SPRITE_DIM, 200));

    while(isRunning) {
        time_last = time_now;
        time_now = SDL_GetTicks();
        delay = time_now - time_last;

        game.tick(delay);

        //process events
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT: {
                    isRunning = false;
                }
            }
        }

        game_renderer.render();
    }

    game_renderer.quit();
    SDL_Quit();

    return 0;
}

