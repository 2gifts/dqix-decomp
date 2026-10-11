#include <globaldefs.h>
#if defined(jpn)
enum { bitsOffset = 0x21c, modeOffset = 0x5b41 };
#else
enum { bitsOffset = 0x2a0, modeOffset = 0x5951 };
#endif
#include "GameState/GameState.h"

struct Obj02049e88;
void ResetSubFlags02049e88(struct Obj02049e88* obj);
void ClearSubstructFlag0x4(unsigned char* obj);
int TestBitAt0x34(unsigned char* obj, unsigned int index);

// USA: func_ov000_02167f10  (semantic: ResetSubFlagsForCombatants_02167f10)
extern "C" ARM void func_ov000_02167f10(unsigned char* obj) {
    GameState* bs = GameState::GetInstance();
    GameObject* c;
    int i;
    for (i = 0; i < 4; i++) {
        if (TestBitAt0x34(*(unsigned char**)(obj + bitsOffset), i & 0xff)) {
            c = bs->GetCombatantByIndex(i);
            if (c) {
                ResetSubFlags02049e88((struct Obj02049e88*)c);
                ClearSubstructFlag0x4((unsigned char*)c);
            }
        }
    }
    for (i = 0xc0; i < 0xc8; i++) {
        c = bs->GetCombatantByIndex(i);
        if (c) {
            ResetSubFlags02049e88((struct Obj02049e88*)c);
            ClearSubstructFlag0x4((unsigned char*)c);
        }
    }
    obj[modeOffset] &= ~0x3;
}
