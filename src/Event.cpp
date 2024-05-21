
#include "Event.h"

bool compareEvent(const Event &e1, const Event &e2) {
    if (e1.p.x == e2.p.x) {
        return e1.p.y < e2.p.y;
    }
    return e1.p.x < e2.p.x;
}
