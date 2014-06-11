#include <iostream>
#include <SDL2/SDL.h>

#include "map.h"

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window;
    SDL_CreateWindow("SDL Test", 0, 0, 640, 480, 0);
    bool isRunning = true;
    SDL_Event event;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface *tile_surface = SDL_LoadBMP("gfx/tile.bmp");
    SDL_Texture *tile = SDL_CreateTextureFromSurface(renderer, tile_surface);

    Map map;

    map.loadMap("levels/map.level");

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

