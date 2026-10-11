#include <globaldefs.h>
#if defined(jpn)
enum { slotLow = 0x12c, slotHigh = 0x7800, counterOffset = 0x7930 };
#else
enum { slotLow = 0x33c, slotHigh = 0x7400, counterOffset = 0x7740 };
#endif
#include "Util/Random.h"

// USA: func_ov000_021637fc  (semantic: PickOpenSlotForId_021637fc)
extern "C" ARM int func_ov000_021637fc(void* obj, int id) {
    int i;
    signed char last;
    char* p;
    if (id < 0 || id >= 4) {
        return 0;
    }
    p = (char*)obj + slotLow;
    last = -1;
    i = 0;
    p = p + slotHigh;
    while (i < 4) {
        signed char v = p[i];
        if (v < 0) {
            int r;
            struct Random* rng;
            p[i] = (char)id;
            rng = GetBTRandom();
            if (last < 0) {
                r = 0;
            } else {
                r = last + NextRandomBetween(rng, 3, 10);
            }
            *((char*)obj + i + counterOffset) = (char)r;
            return 1;
        }
        last = *((char*)obj + i + counterOffset);
        i++;
    }
    return 0;
}
