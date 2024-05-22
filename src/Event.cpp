#include "Event.h"

bool compareEvent(const Event &e1, const Event &e2) {
    if (e1.p.m_x == e2.p.m_x) {
        return e1.p.m_y < e2.p.m_y;
    }
    return e1.p.m_x < e2.p.m_x;
}
