#include <globaldefs.h>
#include "Combat/FormationPosition.h"

static inline int FxMul(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

static inline Vec2_0216f74c GetFormationPosition(const int& cell) {
    return func_ov000_0216f74c(const_cast<int*>(&cell));
}

// USA: func_ov025_021e1480
extern "C" ARM unsigned char func_ov025_021e1480(unsigned char startCell, unsigned char* cells, int count) {
    unsigned char nearest = 0;
    Vec2_0216f74c origin = GetFormationPosition(startCell);
    int bestDist = 0x400000;
    for (int i = 0; i < count; i++) {
        Vec2_0216f74c pos = GetFormationPosition(cells[i]);
        int dist = FxMul(origin.x - pos.x, origin.x - pos.x) + FxMul(origin.y - pos.y, origin.y - pos.y);
        if (dist < bestDist) {
            nearest = cells[i];
            bestDist = dist;
        }
    }
    return nearest;
}
