#include "torchanimation.h"

TorchAnimation::TorchAnimation(int x, int y, int width, int height, int delay) : Animation(x, y, width, height, delay) {
    this->frame.x=x;
    this->frame.y=y;
    this->frame.w = width;
    this->frame.h = height;
}

SDL_Rect TorchAnimation::getAnimationFrame(int now) {
    if((now - this->last) > this->delay) {
        this->last = now;
        this->frame.x = (this->frame.x+width)%(width*2);
    }
    return this->frame;
}
