#include "Event.h"

/**
 * @brief Compares two events for ordering.
 *
 * This function compares two Event objects based on the x-coordinate of their associated points.
 * If the x-coordinates are equal, it compares the y-coordinates. This comparison is essential
 * for sorting events in the event queue of the Bentley-Ottmann sweep line algorithm.
 *
 * @param e1 The first event to compare.
 * @param e2 The second event to compare.
 * @return true if the first event is less than the second event, false otherwise.
 */
bool compareEvent(const Event &e1, const Event &e2) {
    if (e1.p.m_x == e2.p.m_x) {
        return e1.p.m_y < e2.p.m_y; ///< If x-coordinates are equal, compare by y-coordinates
    }
    return e1.p.m_x < e2.p.m_x; ///< Compare by x-coordinates
}
