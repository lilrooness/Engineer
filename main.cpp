#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "map.h"

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("SDL Test", 0, 0, 640, 480, 0);
    bool isRunning = true;
    SDL_Event event;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface *tileset_surface = SDL_LoadBMP("gfx/engineer_tileset.bmp");
    SDL_Texture *tileset = SDL_CreateTextureFromSurface(renderer, tileset_surface);
    SDL_FreeSurface(tileset_surface);

    Map map;

    map_dims dims = map.loadBinaryMap("levels/map.bin");

    SDL_Rect src_rect;

    src_rect.w = 16;
    src_rect.h = 16;

    SDL_Rect dst_rect;

    dst_rect.w = 30;
    dst_rect.h = 30;

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
                grid_point point = map.id_map[map.unsigned_map[y][x]];
                src_rect.x = point.x * 16;
                src_rect.y = point.y * 16;
                dst_rect.x = x * 30;
                dst_rect.y = y * 30;
                SDL_RenderCopy(renderer, tileset, &src_rect, &dst_rect);
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

