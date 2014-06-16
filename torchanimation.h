#ifndef TORCHANIMATION_H
#define TORCHANIMATION_H

#include "animation.h"

class TorchAnimation : public Animation
{
public:
    TorchAnimation(int x, int y, int width, int height, int delay);

    SDL_Rect getAnimationFrame(int now);
};

#endif // TORCHANIMATION_H
