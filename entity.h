#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
    Entity(int x, int y, int sprite_id);
    Entity();
    int sprite_id;
    int x, y;
};

#endif // ENTITY_H
