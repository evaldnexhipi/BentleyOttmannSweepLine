#ifndef COMPARESEGMENT_H
#define COMPARESEGMENT_H

#include "Segment.h"

// Documentation for the CompareSegment structure

/**
 * @brief A structure to compare two segments based on their y-coordinates at a specific x-coordinate.
 *
 * The CompareSegment structure provides a functor (function object) that allows
 * comparison of two Segment objects. The comparison is based on the y-coordinates
 * of the segments at a predefined x-coordinate. If the y-coordinates are equal,
 * the segments are further compared based on their left x-coordinates.
 */
struct CompareSegment {
    static double x; // Declare the static variable `x` as extern to avoid multiple definitions across translation units

    /**
     * @brief Compare two segments based on their y-coordinates at a specific x-coordinate.
     *
     * This operator function allows the CompareSegment structure to be used as a functor.
     * It compares two Segment objects, `s1` and `s2`, by computing their y-coordinates at
     * the static x-coordinate `x`. If the y-coordinates are different, it returns true if
     * the y-coordinate of `s1` is less than that of `s2`. If the y-coordinates are equal,
     * it compares the segments based on their left x-coordinates.
     *
     * @param s1 The first segment to compare.
     * @param s2 The second segment to compare.
     * @return true if `s1` is less than `s2`, false otherwise.
     */
    bool operator()(const Segment &s1, const Segment &s2) const {
        double y1 = s1.ComputeYatX(x); // Compute y-coordinate of the first segment at x
        double y2 = s2.ComputeYatX(x); // Compute y-coordinate of the second segment at x

        if (y1 != y2)
            return y1 < y2; // Compare based on y-coordinates
        return s1.m_left.m_x < s2.m_left.m_x; // If y-coordinates are equal, compare based on left x-coordinates
    }
};

#endif // COMPARESEGMENT_H
