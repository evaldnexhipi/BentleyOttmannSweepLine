#ifndef SWEEPLINEALGORITHM_H
#define SWEEPLINEALGORITHM_H

#include <vector>
#include "Segment.h"
#include "Point.h"
#include "Event.h"

/**
 * @brief Finds all intersections among a set of line segments using the Bentley-Ottmann sweep line algorithm.
 *
 * This function implements the Bentley-Ottmann sweep line algorithm to find all intersection points
 * among a given set of line segments. The algorithm is efficient and handles events where segments
 * start, end, or intersect, maintaining a dynamic status of the sweep line to detect intersections.
 *
 * @param segments A reference to a vector of segments to be checked for intersections.
 * @return A vector of points representing all intersection points found among the segments.
 */
std::vector<Point> findIntersections(std::vector<Segment> &segments);

#endif // SWEEPLINEALGORITHM_H
