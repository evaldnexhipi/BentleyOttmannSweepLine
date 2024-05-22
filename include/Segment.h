#ifndef SEGMENT_H
#define SEGMENT_H

#include "Point.h"

struct Segment {
    Point m_left, m_right;

    // Method to compute the y-coordinate at a given x-coordinate
    double ComputeYatX(const double x) const {
        if (m_left.m_x == m_right.m_x) {
            return m_left.m_y; // Vertical line case
        }
        double slope = (m_right.m_y - m_left.m_y) / (m_right.m_x - m_left.m_x);
        double intercept = m_left.m_y - slope * m_left.m_x;
        return slope * x + intercept;
    }

    // Equality operator
    bool operator==(const Segment &other) const {
        return m_left.m_x == other.m_left.m_x && m_left.m_y == other.m_left.m_y &&
               m_right.m_x == other.m_right.m_x && m_right.m_y == other.m_right.m_y;
    }
};

#endif // SEGMENT_H
