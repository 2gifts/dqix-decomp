#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e3084 func_ov023_021e33dc
#endif
#include "GameState/GameState.h"

int GetField4340_021bdbe4(unsigned char* base);
int GetField433c_021bdbd8(unsigned char* base);
extern "C" void func_ov023_021e5628(void* addr, void* pair);

struct Pair021e3084 { int a; int b; };

#if defined(jpn)
enum { PairCounterOffset = 0x130, PairFlagsOffset = 0x56c, PairDestinationOffset = 0x124 };
#else
enum { PairCounterOffset = 0x134, PairFlagsOffset = 0x634, PairDestinationOffset = 0x128 };
#endif

// USA: func_ov023_021e3084  (semantic: DecrementCounterAndDispatchPair_021e3084)
extern "C" ARM void func_ov023_021e3084(void* obj) {
    GameState::GetInstance();

    if (*(int*)((char*)obj + PairCounterOffset) > 0) {
        if (--*(int*)((char*)obj + PairCounterOffset) == 0) {
            *(unsigned short*)((char*)obj + PairFlagsOffset) |= 8;
        }
    }

    if ((*(unsigned short*)((char*)obj + PairFlagsOffset) & 0x20) == 0) {
        return;
    }

    int h = ((int)func_ov017_0218b5b0());
    Pair021e3084 p;
    if (h == 0) {
        p.b = 0;
        p.a = 0;
    } else {
        p.b = GetField4340_021bdbe4((unsigned char*)h);
        p.a = GetField433c_021bdbd8((unsigned char*)h);
    }

    if (*(int*)((char*)obj + PairDestinationOffset) != 0) {
        *(int*)0x4000444 = 0;
        func_ov023_021e5628(*(void**)((char*)obj + PairDestinationOffset), &p);
        *(int*)0x4000448 = 1;
    }
}
