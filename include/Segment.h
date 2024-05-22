#ifndef SEGMENT_H
#define SEGMENT_H

#include "Point.h"

/**
 * @brief A structure to represent a line segment in 2D space.
 *
 * The Segment structure is used to represent a line segment in 2-dimensional space.
 * It contains two points, `m_left` and `m_right`, which represent the endpoints of the segment.
 * Additionally, it provides methods to compute the y-coordinate at a given x-coordinate and
 * to check equality between segments.
 */
struct Segment {
    Point m_left;  ///< The left endpoint of the segment.
    Point m_right; ///< The right endpoint of the segment.

    /**
     * @brief Method to compute the y-coordinate at a given x-coordinate.
     *
     * This method calculates the y-coordinate of the segment at a specific x-coordinate.
     * It handles the vertical line case separately. For non-vertical segments, it uses
     * the line equation derived from the endpoints.
     *
     * @param x The x-coordinate at which to compute the y-coordinate.
     * @return The y-coordinate of the segment at the given x-coordinate.
     */
    double ComputeYatX(const double x) const {
        if (m_left.m_x == m_right.m_x) {
            return m_left.m_y; // Vertical line case
        }
        double slope = (m_right.m_y - m_left.m_y) / (m_right.m_x - m_left.m_x); ///< Calculate the slope of the segment
        double intercept = m_left.m_y - slope * m_left.m_x; ///< Calculate the y-intercept of the segment
        return slope * x + intercept; ///< Calculate the y-coordinate at the given x
    }

    /**
     * @brief Equality operator to compare two segments.
     *
     * This operator function allows the Segment structure to be compared for equality.
     * Two segments are considered equal if their corresponding endpoints are equal.
     *
     * @param other The segment to compare with.
     * @return true if the segments are equal, false otherwise.
     */
    bool operator==(const Segment &other) const {
        return m_left.m_x == other.m_left.m_x && m_left.m_y == other.m_left.m_y &&
               m_right.m_x == other.m_right.m_x && m_right.m_y == other.m_right.m_y;
    }
};

#endif // SEGMENT_H
