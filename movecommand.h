#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "Command.h"


class MoveCommand : public Command
{
    public:
        MoveCommand(char dir);
        virtual ~MoveCommand();

        void execute(Entity *e);
        void undo(Entity *e);

        char dir;
    protected:
    private:
};

#endif // MOVECOMMAND_H
