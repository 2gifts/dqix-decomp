#include <globaldefs.h>
#include "Util/Random.h"

extern "C" void* func_ov000_02153710(void*, short);
extern "C" int func_ov000_02159dbc(void*, short);

struct RngHolder_021d90c8 { struct Random* rng; };

// JPN: func_ov024_021d9988
// USA: func_ov024_021d90c8
ARM int RandomScaleField6c125Plus2x_021d90c8(struct RngHolder_021d90c8* holder, unsigned short category, int unused1, int unused2, int unused3, int fallback) {
#if defined(jpn)
 enum {regionalOffset0=0x8b8};
#else
 enum {regionalOffset0=0x950};
#endif
    int inRange = 0;
    if (category <= 3) {
        inRange = 1;
    }
    float value;
    if (inRange) {
        char* base = (char*)func_ov000_02153710(holder->rng, (short)category);
        if (base == NULL) {
            return fallback;
        }
        int idx = *(int*)(base + regionalOffset0);
        unsigned short v = *(unsigned short*)(base + idx * 2 + 0x16c);
        value = v;
    } else {
        int v = func_ov000_02159dbc(holder->rng, (short)category);
        value = v;
    }
    float randomFactor = NextRandomFloatBetween(holder->rng, 0.85f, 1.15f);
    return (int)((125.0f + value * 2.0f) * randomFactor);
}
