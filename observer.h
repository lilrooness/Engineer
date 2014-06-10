#ifndef OBSERVER_H
#define OBSERVER_H

#include "entity.h"
#include "event.h"

class Observer
{
public:
    Observer();

    virtual void onNotify(Entity *entity, Event event) = 0;
};

#endif // OBSERVER_H
