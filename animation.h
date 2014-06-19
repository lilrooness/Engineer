#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>

#include "constants.h"

class Animation
{
public:
    Animation(int x, int y, int width, int height, int delay);
    int x, y, width, height, delay, last;
    virtual SDL_Rect getAnimationFrame(int now) = 0;
    SDL_Rect dst_rect;

protected:
    SDL_Rect frame;
};

#endif // ANIMATION_H
