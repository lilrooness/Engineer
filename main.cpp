#include <iostream>
#ifdef WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif // WIN32

#include "game.h"
#include "map.h"
#include "torchanimation.h"
#include "renderer.h"
#include "constants.h"

using namespace std;

int main(int argc, char *argv[]) {

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER);

    SDL_GameController *controller = SDL_GameControllerOpen(0);

    if(controller != NULL) {
        cout<<"Using profile: "<<SDL_GameControllerName(controller)<<endl;
    } else {
        cout<<"No profiled controller connected"<<endl;
    }

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
                case SDL_KEYUP: {
                    switch(event.key.keysym.sym) {
                    case SDLK_w: {
                        MoveCommand* command = new MoveCommand('w');
                        game.commands.push(command);
                    }break;
                    case SDLK_a: {
                        MoveCommand* command = new MoveCommand('a');
                        game.commands.push(command);
                    }break;
                    case SDLK_s: {
                        MoveCommand* command = new MoveCommand('s');
                        game.commands.push(command);
                    }break;
                    case SDLK_d: {
                        MoveCommand* command = new MoveCommand('d');
                        game.commands.push(command);
                    }break;

                    }
                }break;
                case SDL_CONTROLLERBUTTONDOWN: {
                    switch(event.cbutton.button) {
                        case SDL_CONTROLLER_BUTTON_DPAD_UP: {
                            MoveCommand *command = new MoveCommand('w');
                            game.commands.push(command);
                        }break;
                        case SDL_CONTROLLER_BUTTON_DPAD_LEFT: {
                            MoveCommand *command = new MoveCommand('a');
                            game.commands.push(command);
                        }break;
                        case SDL_CONTROLLER_BUTTON_DPAD_DOWN: {
                            MoveCommand *command = new MoveCommand('s');
                            game.commands.push(command);
                        }break;
                        case SDL_CONTROLLER_BUTTON_DPAD_RIGHT: {
                            MoveCommand *command = new MoveCommand('d');
                            game.commands.push(command);
                        }

                    }

                }break;
                default:{}break;
            }
        }

        game_renderer.render(game);
    }

    game_renderer.quit();
    SDL_Quit();

    return 0;
}

