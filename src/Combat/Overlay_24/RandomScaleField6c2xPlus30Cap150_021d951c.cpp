#include <globaldefs.h>
#include "Util/Random.h"

extern "C" void* func_ov000_02153710(void*, short);
extern "C" int func_ov000_02159dbc(void*, short);

struct RngHolder_021d951c { struct Random* rng; };

// JPN: func_ov024_021d9ddc
// USA: func_ov024_021d951c  (semantic: RandomScaleField6c2xPlus30Cap150_021d951c)
extern "C" ARM int func_ov024_021d951c(struct RngHolder_021d951c* holder, unsigned short category, int unused1, int unused2, int unused3, int fallback) {
#if defined(jpn)
 enum {regionalOffset=0x8b8};
#else
 enum {regionalOffset=0x950};
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
        int idx = *(int*)(base + regionalOffset);
        unsigned short v = *(unsigned short*)(base + idx * 2 + 0x16c);
        value = v;
    } else {
        int v = func_ov000_02159dbc(holder->rng, (short)category);
        value = v;
    }
    float adjusted = 30.0f + value * 2.0f;
    if (adjusted > 150.0f) {
        adjusted = 150.0f;
    }
    float randomFactor = NextRandomFloatBetween(holder->rng, -0.1f, 0.1f);
    return (int)(adjusted + adjusted * randomFactor);
}
