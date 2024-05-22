#include "SweepLineAlgorithm.h"
#include "CompareSegment.h"
#include <algorithm>
#include <set>
#include <vector>

double CompareSegment::x = 0.0; // Define the static variable here

// Function to check the orientation of the ordered triplet (p, q, r).
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.m_y - p.m_y) * (r.m_x - q.m_x) - (q.m_x - p.m_x) * (r.m_y - q.m_y);
    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1 : 2; // clock or counter clockwise
}

// Function to check if point q lies on segment pr
bool onSegment(Point p, Point q, Point r) {
    if (q.m_x <= std::max(p.m_x, r.m_x) && q.m_x >= std::min(p.m_x, r.m_x) &&
        q.m_y <= std::max(p.m_y, r.m_y) && q.m_y >= std::min(p.m_y, r.m_y))
        return true;
    return false;
}

// Function to check if two segments (p1q1) and (p2q2) intersect
bool doIntersect(Segment s1, Segment s2) {
    Point p1 = s1.m_left, q1 = s1.m_right;
    Point p2 = s2.m_left, q2 = s2.m_right;

    // Find the four orientations needed for general and special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are collinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are collinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are collinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are collinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

// Function to calculate the intersection point of two segments
Point calculateIntersection(Segment s1, Segment s2) {
    Point p1 = s1.m_left, q1 = s1.m_right;
    Point p2 = s2.m_left, q2 = s2.m_right;

    double a1 = q1.m_y - p1.m_y;
    double b1 = p1.m_x - q1.m_x;
    double c1 = a1 * p1.m_x + b1 * p1.m_y;

    double a2 = q2.m_y - p2.m_y;
    double b2 = p2.m_x - q2.m_x;
    double c2 = a2 * p2.m_x + b2 * p2.m_y;

    double determinant = a1 * b2 - a2 * b1;

    if (determinant == 0) {
        // The lines are parallel
        return {0, 0}; // Should not happen as we check for intersection first
    } else {
        double x = (b2 * c1 - b1 * c2) / determinant;
        double y = (a1 * c2 - a2 * c1) / determinant;
        return {x, y};
    }
}

std::vector<Point> findIntersections(std::vector<Segment> &segments) {
    std::vector<Point> intersections;

    std::vector<Event> events;
    for (Segment &s : segments) {
        events.push_back({s.m_left, true, s});
        events.push_back({s.m_right, false, s});
    }

    std::sort(events.begin(), events.end());

    std::vector<Segment> sweepLine;
    CompareSegment comparator;

    std::set<std::pair<int, int>> uniqueIntersections; // To track unique intersection points

    for (auto &e : events) {
        CompareSegment::x = e.p.m_x; // Update the current x-coordinate for comparison

        if (e.isStart) {
            sweepLine.push_back(e.s);
            std::sort(sweepLine.begin(), sweepLine.end(), comparator);
            // Check for intersections with adjacent segments
            auto it = std::find(sweepLine.begin(), sweepLine.end(), e.s);
            if (it != sweepLine.end()) {
                if (it != sweepLine.begin()) {
                    auto prev = std::prev(it);
                    if (doIntersect(*prev, *it)) {
                        Point intersection = calculateIntersection(*prev, *it);
                        if (uniqueIntersections.insert({intersection.m_x, intersection.m_y}).second) {
                            intersections.push_back(intersection);
                        }
                    }
                }
                auto next = std::next(it);
                if (next != sweepLine.end()) {
                    if (doIntersect(*it, *next)) {
                        Point intersection = calculateIntersection(*it, *next);
                        if (uniqueIntersections.insert({intersection.m_x, intersection.m_y}).second) {
                            intersections.push_back(intersection);
                        }
                    }
                }
            }
        } else {
            auto it = std::find(sweepLine.begin(), sweepLine.end(), e.s);
            if (it != sweepLine.end()) {
                auto next = std::next(it);
                if (it != sweepLine.begin() && next != sweepLine.end()) {
                    auto prev = std::prev(it);
                    if (doIntersect(*prev, *next)) {
                        Point intersection = calculateIntersection(*prev, *next);
                        if (uniqueIntersections.insert({intersection.m_x, intersection.m_y}).second) {
                            intersections.push_back(intersection);
                        }
                    }
                }
                sweepLine.erase(it);
            }
        }
    }

    return intersections;
}
