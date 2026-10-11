#include <globaldefs.h>

struct ZoneState { unsigned short zoneId; unsigned short previousZoneId; };
struct Obj0201b600;
struct ZoneResourceState {
    char pad0[0x1b3c];
    int progress;
};

extern "C" ZoneState* func_02012fe4();
extern "C" int _s32_div_f(int a, int b);
extern "C" int _Z19IsIdInRange020981e4ii(int a, int id);
extern "C" int _Z19IsIdInRange02098240ii(int a, int id);
extern "C" int func_0201bd74(Obj0201b600* obj, unsigned int argA, int argB);

// USA: func_02098080
extern "C" ARM int func_02098080(ZoneResourceState* state) {
    ZoneState* zone = func_02012fe4();
    int zoneId = zone->zoneId;
    int v, progress;
    progress = state->progress;
    v = _s32_div_f(zone->zoneId, 100) - 500;

    if (!_Z19IsIdInRange020981e4ii((int)state, zoneId)) return 0;
    if (_Z19IsIdInRange02098240ii((int)state, zoneId)) return 0;
    if (zoneId == 0xc3bb) return 0;
    if ((unsigned int)(zoneId - 0xc3bc) <= 2) return 0;

    switch (progress) {
    case 0:
        break;
    case 1:
        if (v == 1) break;
        return 1;
    case 2:
        if (v != 1) return 1;
        if (zoneId != 0xc3b5) break;
        if (func_0201bd74((Obj0201b600*)zone, 9, 0) == 0) break;
        return 1;
    case 3:
        if (v == 2) break;
        return 1;
    case 4:
        if (v != 2) return 1;
        if (zoneId != 0xc41b) break;
        if (func_0201bd74((Obj0201b600*)zone, 20, 0) == 0) break;
        return 1;
    case 5:
        if (v == 3) break;
        return 1;
    case 6:
        if (v != 4) return 1;
        break;
    }
    return 0;
}
