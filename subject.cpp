#include "subject.h"

Subject::Subject()
{
}

void Subject::addObserver(Observer *observer) {
    observers.push_back(observer);
}
