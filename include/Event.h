
#ifndef EVENT_H
#define EVENT_H

#include "Point.h"
#include "Segment.h"

struct Event {
    Point p;
    bool isStart;
    Segment s;
};

bool compareEvent(const Event &e1, const Event &e2);

#endif // EVENT_H
