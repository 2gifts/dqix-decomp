#include <globaldefs.h>
#include "Util/Random.h"

extern "C" void* func_ov000_02153710(void*, short);
extern "C" int func_ov000_02159dbc(void*, short);

struct RngHolder_021d947c { struct Random* rng; };

// JPN: func_ov024_021d9d3c
// USA: func_ov024_021d947c
ARM int RandomScaleField6cBy3_021d947c(struct RngHolder_021d947c* holder, unsigned short category, int unused1, int unused2, int unused3, int fallback) {
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
    float randomFactor = NextRandomFloatBetween(holder->rng, 0.9f, 1.1f);
    return (int)(3.0f * value * randomFactor);
}
