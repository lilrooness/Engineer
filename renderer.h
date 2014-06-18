#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <animation.h>
#include "map.h"

class Renderer {
public:
    Renderer();

    std::vector<Animation*> animations;
    Map map;
    SDL_Texture *tileset;
    SDL_Texture *spritesheet;
    SDL_Renderer *renderer;
    SDL_Window *window;
    map_dims dims;
};

#endif // RENDERER_H
