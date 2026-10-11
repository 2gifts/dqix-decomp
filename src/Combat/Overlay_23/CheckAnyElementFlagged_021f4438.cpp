#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
void* GetPtrField0x2a04(GameState*);

struct Obj021f4438 {
#if defined(jpn)
    char pad0[0x5af0];
#else
    char pad0[0x5900];
#endif
    unsigned char byte5900;
    signed char byte5901;
#if defined(jpn)
    char pad1[0x7014 - 0x5af2];
#else
    char pad1[0x6e24 - 0x5902];
#endif
    int f6e24;
};

struct ElemBlock021f4438 {
    char pad0[0xf78];
    unsigned char shiftAmt;
    char pad1[0xf7c - 0xf79];
    unsigned char count;
};

// USA: func_ov023_021f4438  (semantic: CheckAnyElementFlagged_021f4438)
extern "C" ARM int func_ov023_021f4438(Obj021f4438* obj) {
    int result = 0;
    if (obj->byte5900 != 0 || obj->f6e24 != 0) {
        GameState* battleStruct = GameState::GetInstance();
        void* p = func_0202ae18();
        result = 1;
        if (CheckField0NonZero((int*)p)) {
            ElemBlock021f4438* base = (ElemBlock021f4438*)GetPtrField0x2a04(battleStruct);
            int found = 0;
            int i;
            for (i = 0; i < base->count; i++) {
                ElemBlock021f4438* elem = (ElemBlock021f4438*)((char*)base + i);
                if (obj->byte5901 & (1 << elem->shiftAmt)) {
                    found = 1;
                    break;
                }
            }
            if (!found) result = 0;
        }
    }
    return result;
}
