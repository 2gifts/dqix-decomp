#include <globaldefs.h>
#if defined(jpn)
enum { bitsOffset = 0x21c, modeOffset = 0xb41 };
#else
enum { bitsOffset = 0x2a0, modeOffset = 0x951 };
#endif
#include "GameState/GameState.h"

int TestBitAt0x34(unsigned char* obj, unsigned int index);
extern "C" void func_02049e00(void);

// USA: func_ov000_02167dd8
ARM void RunFlagPassAndSetMode02167dd8_02167dd8(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    for (int i = 0; i < 4; i++) {
        if (TestBitAt0x34(*(unsigned char**)(obj + bitsOffset), (unsigned char)i)) {
            if (battle->GetCombatantByIndex(i)) func_02049e00();
        }
    }
    for (int i = 0xc0; i < 0xc8; i++) {
        if (battle->GetCombatantByIndex(i)) func_02049e00();
    }
    unsigned char b = *(unsigned char*)(obj + 0x5000 + modeOffset);
    b = (b & ~3) | 2;
    *(unsigned char*)(obj + 0x5000 + modeOffset) = b;
}
