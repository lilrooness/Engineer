#include "renderer.h"

#include "constants.h"

using namespace std;

Renderer::Renderer() {
    IMG_Init(IMG_INIT_PNG);
    this->window = SDL_CreateWindow("Engineer", 0, 0, 640, 480, 0);
    this->renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface *tileset_surface = SDL_LoadBMP("gfx/engineer_tileset.bmp");
    SDL_Surface *spritesheet_surface = IMG_Load("gfx/spritesheet.png");

    SDL_SetColorKey(tileset_surface, 1, ALPHA);

    this->tileset = SDL_CreateTextureFromSurface(renderer, tileset_surface);
    this->spritesheet = SDL_CreateTextureFromSurface(renderer, spritesheet_surface);

    this->dims = game.map.loadBinaryMap("levels/map.bin");

    this->src_rect.w = SHEET_TILE_DIM;
    this->src_rect.h = SHEET_TILE_DIM;

    this->dst_rect.w = TILE_DIM;
    this->dst_rect.h = TILE_DIM;
}

void Renderer::render(Game game) {
    //draw map
    for(int y=0; y<dims.rows; y++) {
        for(int x=0; x<dims.cols; x++) {
            grid_point point = game.map.id_map[game.map.unsigned_map[y][x]];
            src_rect.x = point.x * SHEET_TILE_DIM;
            src_rect.y = point.y * SHEET_TILE_DIM;
            dst_rect.x = x * TILE_DIM;
            dst_rect.y = y * TILE_DIM;
            SDL_RenderCopy(renderer, tileset, &src_rect, &dst_rect);
        }
    }

    renderAnimations();
    SDL_RenderPresent(renderer);
}

void Renderer::renderAnimations() {
    for(int i=0; i<animations.size(); i++) {
        SDL_Rect animation_frame = animations.at(i)->getAnimationFrame(SDL_GetTicks());
        SDL_Rect dst_rect = animations.at(i)->dst_rect;
        SDL_RenderCopy(renderer, spritesheet, &animation_frame, &dst_rect);
    }

    SDL_Rect player_src;
    player_src.w = SHEET_TILE_DIM;
    player_src.h = SHEET_TILE_DIM;

    SDL_Rect player_dst;
    grid_point player_point = game.map.id_map[game.player.sprite_id];
    player_src.x = player_point.x * SHEET_TILE_DIM;
    player_src.y = player_point.y * SHEET_TILE_DIM;

    player_dst.x = game.player.x * TILE_DIM;
    player_dst.y = game.player.y * TILE_DIM;
    player_dst.w = TILE_DIM;
    player_dst.h = TILE_DIM;

    SDL_RenderCopy(renderer, tileset, &player_src, &player_dst);
}

void Renderer::quit() {
    SDL_DestroyWindow(this->window);
    IMG_Quit();
}
