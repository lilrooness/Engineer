#ifndef ANIMATION_H
#define ANIMATION_H
#ifdef WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

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
