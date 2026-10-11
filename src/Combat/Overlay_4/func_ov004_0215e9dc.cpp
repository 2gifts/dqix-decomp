#include <globaldefs.h>
#include "GameState/GameState.h"


unsigned short GetFlagBitFromField150_0215eb20(void* obj, int bit);

extern int data_ov004_02170854[];
extern unsigned char data_ov004_02170838[];
extern unsigned char data_ov004_021707e8;
#if defined(jpn)

extern "C" GameObject* GetCombatantWithFlag0x100(GameState*, int);
#else
#endif

// USA: func_ov004_0215e9dc
// JPN: func_ov004_0215f4e4
extern "C" ARM int func_ov004_0215e9dc(void* unused, void* combatantIdPtr, int counter, int dir) {
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), (int)combatantIdPtr);
    int idx = counter;

    if (data_ov004_02170854[idx] == 0) {
        goto done;
    }

    if (dir) {
        idx = (unsigned char)(idx + 1);
        idx = (unsigned char)(idx % 0xd);
        if (idx == 0) idx = 1;
    } else {
        idx = (unsigned char)(idx - 1);
        if ((unsigned)idx < 1) idx = 0xc;
    }

    goto loop_test;
loop_body:
    if (dir) {
        idx = (unsigned char)(idx + 1);
        idx = (unsigned char)(idx % 0xd);
        if (*((unsigned char*)&data_ov004_021707e8 + 2) && idx == 0) idx = (unsigned char)(idx + 1);
        if (!GetFlagBitFromField150_0215eb20(combatant, data_ov004_02170854[idx]) || !data_ov004_02170838[idx]) goto loop_test;
        goto done;
    } else {
        idx = (unsigned char)(idx - 1);
        if ((unsigned)idx < 1) idx = 0xc;
        if (*((unsigned char*)&data_ov004_021707e8 + 2) && idx == 0) idx = 0xc;
        if (!GetFlagBitFromField150_0215eb20(combatant, data_ov004_02170854[idx]) || !data_ov004_02170838[idx]) goto loop_test;
        goto done;
    }
loop_test:
    if (!GetFlagBitFromField150_0215eb20(combatant, data_ov004_02170854[idx]) || !data_ov004_02170838[idx]) goto loop_body;
done:
    return idx;
}
