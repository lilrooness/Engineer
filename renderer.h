#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <SDL2/SDL_image.h>

#include "animation.h"
#include "map.h"
#include "game.h"

class Renderer {
public:
    Renderer();

    void render();
    void renderAnimations();
    void quit();

    std::vector<Animation*> animations;

    SDL_Texture *tileset;
    SDL_Texture *spritesheet;
    SDL_Renderer *renderer;
    SDL_Window *window;

    Game game;

//    Map map;
    map_dims dims;

    SDL_Rect src_rect;
    SDL_Rect dst_rect;
};

#endif // RENDERER_H
