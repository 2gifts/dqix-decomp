#include <globaldefs.h>

struct ClassifyPointRegionStruct {
    char pad0[0xc];
    int fieldc;
    short field10;
    short field12;
};

// USA: func_020c965c
#pragma optimize_for_size off
ARM int ClassifyPointRegion_020c965c(struct ClassifyPointRegionStruct* p, int x, int y) {
    int dx = x - p->fieldc;
    int dy = y - p->field10;
    if (dx < 0 || (dx == 0 && dy < 0)) return 0;
    if (dy < 0) dy += 0x107;
    if (dy <= p->field12) return 1;
    return 2;
}
