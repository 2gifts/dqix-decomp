#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* battleStruct, int combatantId);
extern "C" int _Z34ClassifyFlag0x800RatioTier02027bd0i(int id);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" int LoadToSubObjStandardPalette(int arg0, int arg1, unsigned int arg2);

extern unsigned char data_020e703e[];
extern unsigned short data_020e7044[] __attribute__((aligned(4)));

struct Global020fdc4c_020276dc {
    unsigned short field0;
    char pad[0x12];
};
extern struct Global020fdc4c_020276dc data_020fdc4c;
extern struct Global020fdc4c_020276dc data_020fdc4c_dup;

// USA: func_020276dc
extern "C" ARM void func_020276dc(unsigned char* self) {
    GameState* gs = GameState::GetInstance();
    unsigned i;
    unsigned short buf[4];
    for (i = 0; i < 4; i++) {
        int cur;
        int sh;
        int have;
        unsigned char want;

        int k;

        if (_Z25GetCombatantWithFlag0x100P9GameStatei(gs, i) == 0) continue;
        want = data_020e703e[_Z34ClassifyFlag0x800RatioTier02027bd0i(i)];
        cur = self[0];
        sh = i << 1;
        have = (cur >> sh) & 3;
        if (have == want) continue;

        cur &= ~(3 << sh);
        self[0] = (unsigned char)cur;
        *(volatile unsigned char*)self = (unsigned char)((cur & 0xff) | (want << sh));
        {
            const unsigned short* s = data_020e7044;
            unsigned short* d = buf;
            k = 4;
            do { *d++ = *s++; } while (--k);
        }
        data_020fdc4c.field0 = buf[want];
        CleanInvalidateCacheRange(&data_020fdc4c_dup, 2);
        LoadToSubObjStandardPalette((int)&data_020fdc4c_dup, i * 32 + 0x1e, 2);
    }
}
