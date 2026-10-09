#include <globaldefs.h>
#include "GameState/GameState.h"

struct CounterBlk {
    char pad[0xd];
    unsigned char count;
};
struct SearchStruct {
    int field_0;
    char pad[0x1000 - 4];
    struct CounterBlk blk;
};

void PushInterruptDisableState(void);
extern "C" void func_020d8694(void);
int TestBitBySignedByteIndex(struct SearchStruct* obj, int value);
extern "C" void _Z32StoreValidCombatantCount0202c3e0Pv(void* obj);
extern "C" void _Z24UpdatePlayClocks020ac4f8i(int flag);
unsigned long long GetCurrentTimestamp(void);

// USA: func_0202c288
extern "C" ARM void func_0202c288(struct SearchStruct* obj) {
    PushInterruptDisableState();
    int flag = (*(int*)obj != 0);
    unsigned char saved = obj->blk.count;

    if (!flag) {
        obj->blk.count = 1;
    } else {
        obj->blk.count = 0;
        int i;
        for (i = 0; i < 4; i++) {
            if (TestBitBySignedByteIndex(obj, i)) {
                (*((unsigned char*)obj + 0x100d))++;
            }
        }
        _Z32StoreValidCombatantCount0202c3e0Pv(obj);
    }

    if (*(int*)obj == 5) {
        unsigned char cur = obj->blk.count;
        if (cur == 1) {
            if (saved > 1) {
                _Z24UpdatePlayClocks020ac4f8i(1);
                goto done;
            }
        }

        if (cur > 1) {
            if (saved == 1) {
                GameState* bs = GameState::GetInstance();
                *(unsigned long long*)((char*)bs + 0x3f0) = GetCurrentTimestamp();
            }
        }
    }

done:
    func_020d8694();
}