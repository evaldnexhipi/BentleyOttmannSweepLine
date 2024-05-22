#ifndef EVENT_H
#define EVENT_H

#include "Point.h"
#include "Segment.h"

struct Event {
    Point p;
    bool isStart;
    Segment s;

    Event(Point point, bool start, Segment segment) : p(point), isStart(start), s(segment) {}

    bool operator<(const Event &e) const {
        if (p.m_x == e.p.m_x) {
            return p.m_y < e.p.m_y;
        }
        return p.m_x < e.p.m_x;
    }
};

#endif // EVENT_H
