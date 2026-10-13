#include <globaldefs.h>

#if defined(jpn)
#define func_0208767c func_02087f78
#endif
#include "Util/Random.h"

int CheckField0x14FiveFlagsClear0208810c(unsigned char* obj);
void ResetAndSetFlag0x1000000(void* obj);



// USA: func_0208767c  (semantic: TickCastCounter0208767c)
extern "C" ARM int func_0208767c(unsigned char* obj, struct Random* rng) {
    unsigned char state = obj[0x24];
    if (state >= 4) return -2;
    if (state == 3) {
        if (rng == 0) rng = GetBTRandom();
        if (NextRandomMax(rng, 2) >= 1) return -1;
    }
    if (++obj[0x24] >= 4) {
        if (CheckField0x14FiveFlagsClear0208810c(obj)) {
            obj[0x24] = 4;
            ResetAndSetFlag0x1000000(obj);
        }
    }
    return obj[0x24];
}
