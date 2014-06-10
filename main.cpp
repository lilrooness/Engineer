#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window;
    SDL_CreateWindow("SDL Test", 0, 0, 640, 480, 0);
    bool isRunning = true;
    SDL_Event event;

    while(isRunning) {

        //process events
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT: {
                    isRunning = false;
                }
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

