#include "renderer.h"

#define ALPHA 0xFF00FF

#define WINDOW_W 640
#define WINDOW_H 480

#define TILE_DIM 60
#define SHEET_TILE_DIM 16

#define LARGE_SPRITE_DIM 80 // 16 * 5

using namespace std;

Renderer::Renderer() {
    this->window = SDL_CreateWindow("Engineer", 0, 0, 640, 480, 0);
    this->renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface *tileset_surface = SDL_LoadBMP("engineer_tile.bmp");
    SDL_Surface *spritesheet_surface = SDL_LoadBMP("spritesheet.png");

    this->tileset = SDL_CreateTextureFromSurface(renderer, tileset_surface);
    this->spritesheet = SDL_CreateTextureFromSurface(renderer, spritesheet_surface);

    this->dims = map.loadBinaryMap("map.bin");
}

//void Renderer::render() {
//    //draw map
//    for(int y=0; y<dims.rows; y++) {
//        for(int x=0; x<dims.cols; x++) {
//            grid_point point = map.id_map[map.unsigned_map[y][x]];
//            src_rect.x = point.x * 16;
//            src_rect.y = point.y * 16;
//            dst_rect.x = x * 30;
//            dst_rect.y = y * 30;
//            SDL_RenderCopy(renderer, tileset, &src_rect, &dst_rect);
//        }
//    }
//    SDL_Rect torch_frame = torch_animation.getAnimationFrame(time_now);
//    SDL_RenderCopy(renderer, spritesheet, &torch_frame, &torch_dst);

//    SDL_RenderPresent(renderer);
//}
