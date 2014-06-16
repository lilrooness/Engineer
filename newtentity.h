#ifndef NEWTENTITY_H
#define NEWTENTITY_H

class NewtEntity
{
public:
    NewtEntity(float xpos, float ypos);

    float xpos, ypos;
    float xvel, yvel;
    float xacc, yacc;
    float mass;

    void applyForce(float x, float y);
    void update(int delay);
};

#endif // NEWTENTITY_H
