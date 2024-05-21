#ifndef COMPARESEGMENT_H
#define COMPARESEGMENT_H

#include "Segment.h"

struct CompareSegment {
    bool operator()(const Segment &s1, const Segment &s2) const {
        // Placeholder logic for comparing two segments
        // This needs to be defined according to your requirements
        // For simplicity, let's compare the starting points
        if (s1.p1.x != s2.p1.x)
            return s1.p1.x < s2.p1.x;
        return s1.p1.y < s2.p1.y;
    }
};

#endif // COMPARESEGMENT_H

