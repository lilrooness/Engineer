#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game.h"
#include "map.h"
#include "torchanimation.h"

#define ALPHA 0xFF00FF

#define WINDOW_W 640
#define WINDOW_H 480

#define TILE_DIM 60
#define SHEET_TILE_DIM 16

#define LARGE_SPRITE_DIM 80 // 16 * 5

using namespace std;

int main(int argc, char *argv[]) {

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    int time_now = 0;
    int time_last = 0;
    int delay = time_now - time_last;

    SDL_Window *window = SDL_CreateWindow("SDL Test", 0, 0, 640, 480, 0);
    bool isRunning = true;
    SDL_Event event;
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface *tileset_surface = SDL_LoadBMP("gfx/engineer_tileset.bmp");
    SDL_Surface *spritesheet_surface = IMG_Load("gfx/spritesheet.png");

    SDL_Texture *spritesheet = SDL_CreateTextureFromSurface(renderer, spritesheet_surface);
    SDL_Texture *tileset = SDL_CreateTextureFromSurface(renderer, tileset_surface);
    SDL_FreeSurface(tileset_surface);

    SDL_Rect screen_rect;
    screen_rect.x = 0;
    screen_rect.y = 0;
    screen_rect.h = WINDOW_H;
    screen_rect.w = WINDOW_W;

    Map map;
    Game game;

    map_dims dims = map.loadBinaryMap("levels/map.bin");

    SDL_Rect src_rect;

    src_rect.w = SHEET_TILE_DIM;
    src_rect.h = SHEET_TILE_DIM;

    SDL_Rect dst_rect;

    dst_rect.w = TILE_DIM;
    dst_rect.h = TILE_DIM;

    SDL_Rect ptcl_dst;
    ptcl_dst.w = 16;
    ptcl_dst.h = 16;

    int half_way = WINDOW_W / 2;

    int h_ratio = WINDOW_H / LARGE_SPRITE_DIM;

    SDL_Rect torch_dst;
    torch_dst.x = half_way - ((80*h_ratio) / 2);
    torch_dst.y = 0;
    torch_dst.w = LARGE_SPRITE_DIM * h_ratio;
    torch_dst.h = LARGE_SPRITE_DIM * h_ratio;

    TorchAnimation torch_animation(0, 0, LARGE_SPRITE_DIM, LARGE_SPRITE_DIM, 100);

    SDL_Rect ambient_light_src;
    ambient_light_src.x = 0;
    ambient_light_src.y = 0;
    ambient_light_src.w = 256;
    ambient_light_src.h = 256;

    SDL_Rect ambient_light_dst;
    ambient_light_dst.x = half_way - (256*h_ratio) / 2;
    ambient_light_dst.y = -128;
    ambient_light_dst.w = 256 * h_ratio;
    ambient_light_dst.h = 256 * h_ratio;

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

        //draw map
        for(int y=0; y<dims.rows; y++) {
            for(int x=0; x<dims.cols; x++) {
                grid_point point = map.id_map[map.unsigned_map[y][x]];
                src_rect.x = point.x * SHEET_TILE_DIM;
                src_rect.y = point.y * SHEET_TILE_DIM;
                dst_rect.x = x * TILE_DIM;
                dst_rect.y = y * TILE_DIM;
                SDL_RenderCopy(renderer, tileset, &src_rect, &dst_rect);
            }
        }
        SDL_Rect torch_frame = torch_animation.getAnimationFrame(time_now);
        SDL_RenderCopy(renderer, spritesheet, &torch_frame, &torch_dst);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}

