#include "animation.h"

Animation::Animation(int x, int y, int width, int height, int delay): x(x),y(y),width(width),height(height),delay(delay) {
    this->last = SDL_GetTicks();
}
