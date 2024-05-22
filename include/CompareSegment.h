#ifndef COMPARESEGMENT_H
#define COMPARESEGMENT_H

#include "Segment.h"

struct CompareSegment {
    static double x; // Declare as extern to avoid multiple definitions

    bool operator()(const Segment &s1, const Segment &s2) const {
        double y1 = s1.ComputeYatX(x);
        double y2 = s2.ComputeYatX(x);

        if (y1 != y2)
            return y1 < y2;
        return s1.m_left.m_x < s2.m_left.m_x;
    }
};

#endif // COMPARESEGMENT_H
