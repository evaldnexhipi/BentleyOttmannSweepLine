#ifndef POINT_H
#define POINT_H

/**
 * @brief A structure to represent a point in 2D space.
 *
 * The Point structure is used to represent a point in 2-dimensional space.
 * It contains x and y coordinates and provides a comparison operator to
 * facilitate sorting and ordering of points.
 */
struct Point {
    double m_x; ///< The x-coordinate of the point.
    double m_y; ///< The y-coordinate of the point.

    /**
     * @brief Default constructor initializes point to origin (0,0).
     *
     * The default constructor sets the coordinates of the point to (0,0).
     */
    Point() : m_x(0), m_y(0) {}

    /**
     * @brief Parameterized constructor to initialize a point with given coordinates.
     *
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     */
    Point(double x, double y) : m_x(x), m_y(y) {}

    /**
     * @brief Comparison operator to order points.
     *
     * This operator function allows the Point structure to be used in sorting operations.
     * Points are compared primarily by their x-coordinates. If the x-coordinates are equal,
     * the y-coordinates are used for comparison. This ordering is useful in various
     * computational geometry algorithms.
     *
     * @param p The point to compare with.
     * @return true if this point is less than the point `p`, false otherwise.
     */
    bool operator<(const Point &p) const {
        return m_x < p.m_x || (m_x == p.m_x && m_y < p.m_y); ///< Compare by x-coordinate, then by y-coordinate
    }
};

#endif // POINT_H
