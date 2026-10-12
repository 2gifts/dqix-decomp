#include <globaldefs.h>

#if defined(jpn)
#define func_020ac234 func_020add00
enum { BattleBaseOffset = 0x3880 };
#else
enum { BattleBaseOffset = 0x3ac0 };
#endif
#include "GameState/GameState.h"

struct Elem020ac234 {
    unsigned short a;
    unsigned short bit0 : 1;
    unsigned short bit1 : 1;
    unsigned short rest : 14;
};

// USA: func_020ac234  (semantic: RepackBattleFlagArray020ac234)
extern "C" ARM int func_020ac234(struct Elem020ac234* dst) {
    char* base = (char*)GameState::GetInstance() + BattleBaseOffset + 0x4000;
    unsigned short* src = (unsigned short*)(base + 4);
    int i;
    for (i = 0; i < 0x1d7; i++) {
        struct Elem020ac234* e = &dst[i];
        e->a = (src[i] & 0xfffc) >> 2;
        e->bit0 = (src[i] & 2) >> 1;
        e->bit1 = src[i] & 1;
    }
    return 1;
}
