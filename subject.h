#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include "observer.h"

class Subject {
public:
    Subject();
    std::vector<Observer*> observers;
    void addObserver(Observer *observer);
};

#endif // SUBJECT_H
