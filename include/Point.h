#ifndef POINT_H
#define POINT_H

struct Point {
    double m_x, m_y;

    Point() : m_x(0), m_y(0) {}
    Point(double x, double y) : m_x(x), m_y(y) {}

    bool operator<(const Point &p) const {
        return m_x < p.m_x || (m_x == p.m_x && m_y < p.m_y);
    }
};

#endif // POINT_H
