#ifndef COMMAND_H
#define COMMAND_H

#include "entity.h"

class Command
{
public:
    virtual void execute(Entity *e) = 0;
    virtual void undo(Entity *e) = 0;
};

#endif // COMMAND_H
