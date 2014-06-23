#include "torchanimation.h"

TorchAnimation::TorchAnimation(int x, int y, int width, int height, int delay) : Animation(x, y, width, height, delay) {
    this->frame.x=x;
    this->frame.y=y;
    this->frame.w = width;
    this->frame.h = height;

    int half_way = WINDOW_W / 2;

    int h_ratio = WINDOW_H / LARGE_SPRITE_DIM;


    //this->dst_rect.x = half_way - ((80*h_ratio) / 2);
    //this->dst_rect.y = 0;
    //this->dst_rect.w = LARGE_SPRITE_DIM * h_ratio;
    //this->dst_rect.h = LARGE_SPRITE_DIM * h_ratio;

    //this gets rid of the bars of map on the left and right sides of the screen
    dst_rect.x = 0;
    dst_rect.y = 0;
    dst_rect.w = WINDOW_W;
    dst_rect.h = WINDOW_H;
}

SDL_Rect TorchAnimation::getAnimationFrame(int now) {
    if((now - this->last) > this->delay) {
        this->last = now;
        this->frame.x = (this->frame.x+width)%(width*2);
    }
    return this->frame;
}
