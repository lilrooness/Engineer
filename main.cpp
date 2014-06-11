#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "map.h"

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window;
    SDL_CreateWindow("SDL Test", 0, 0, 640, 480, 0);
    bool isRunning = true;
    SDL_Event event;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface *tileset_surface = SDL_LoadBMP("gfx/engineer_tileset.bmp");
    SDL_Texture *tileset = SDL_CreateTextureFromSurface(renderer, tileset_surface);
    SDL_FreeSurface(tileset_surface);

    Map map;

    map_dims dims = map.loadMap("levels/map.level");

    while(isRunning) {

        //process events
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT: {
                    isRunning = false;
                }
            }
        }

        for(int y=0; y<dims.rows; y++) {
            for(int x=0; x<dims.cols; x++) {
                switch(map.map[y][x]) {
                    //render tiles
                }
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

