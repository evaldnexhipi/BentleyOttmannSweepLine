#ifndef EVENT_H
#define EVENT_H

#include "Point.h"
#include "Segment.h"

/**
 * @brief A structure to represent an event in the Bentley-Ottmann sweep line algorithm.
 *
 * The Event structure is used to represent events in the Bentley-Ottmann sweep line algorithm,
 * which is an efficient algorithm for finding all intersections in a set of segments. Each event
 * consists of a point, a flag indicating whether it is a start point of a segment, and the segment
 * itself.
 */
struct Event {
    Point p;      ///< The point associated with the event.
    bool isStart; ///< Flag indicating if the event is a start point of a segment.
    Segment s;    ///< The segment associated with the event.

    /**
     * @brief Constructor to initialize an Event object.
     *
     * @param point The point associated with the event.
     * @param start Boolean flag indicating if the event is a start point.
     * @param segment The segment associated with the event.
     */
    Event(Point point, bool start, Segment segment)
        : p(point), isStart(start), s(segment) {}

    /**
     * @brief Comparison operator to order events in the event queue.
     *
     * This operator function allows the Event structure to be used in sorting operations,
     * such as maintaining an event queue in the Bentley-Ottmann sweep line algorithm.
     * Events are compared primarily by the x-coordinate of their points. If the x-coordinates
     * are equal, the y-coordinates are used for comparison. This ensures a correct order of
     * events as the sweep line progresses from left to right.
     *
     * @param e The event to compare with.
     * @return true if this event is less than the event `e`, false otherwise.
     */
    bool operator<(const Event &e) const {
        if (p.m_x == e.p.m_x) {
            return p.m_y < e.p.m_y; ///< If x-coordinates are equal, compare by y-coordinates
        }
        return p.m_x < e.p.m_x; ///< Compare by x-coordinates
    }
};

#endif // EVENT_H
