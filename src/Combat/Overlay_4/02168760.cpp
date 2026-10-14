#include <globaldefs.h>
#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"
#include "System/Memory.h"

struct FieldFlagBlock;
void ResetAndEnableFieldFlag(struct FieldFlagBlock* block);
GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
void EnqueueEventTag58_021cf594(unsigned short, int, int);
extern "C" void* func_02012fe4(void);

// USA: func_ov004_02168760
extern "C" ARM int func_ov004_02168760(void) {
    GameState* bs = GameState::GetInstance();
    ResetAndEnableFieldFlag((struct FieldFlagBlock*)bs);

    char buf[0x70];
    VectorizedMemset(buf, 0, 0x70);

    unsigned char one = 1;
    buf[8] = one;
    buf[9] = one;
    int negOne = one - 2;
    *(signed char*)(buf + 0xb) = negOne;
    *(int*)(buf + 0x20) = negOne;
    *(int*)(buf + 0x24) = negOne;
    *(int*)(buf + 0x28) = negOne;
    *(int*)(buf + 0x2c) = negOne;
    *(short*)(buf + 0x1e) = negOne;
    buf[0xc] = 0;
    *(short*)(buf + 0x6c) = negOne;

    *(unsigned short*)buf = 0x1130;
    *(int*)(buf + 0x14) = -0x5ccc;
    *(int*)(buf + 0x18) = 0x1000;
    *(short*)(buf + 0x1c) = 0x323d;
    buf[2] = one;
    buf[4] = 0;
    buf[5] = 0;
    *(int*)(buf + 0x10) = 0;
    buf[7] = one;

    _Z37CallFunc0200fbb4AtField0x3f8_0200fba4Pv(bs, buf);

    unsigned short zone = *(unsigned short*)func_02012fe4();

    for (signed char i = 1; i < 4; i++) {
        GameObject* member = bs->GetPartyMemberByIndex(i);
        if (!member) continue;
        if (GetCombatantWithFlag0x1000(bs, i)) continue;
        if (member->obj3D_.GetField06() != zone) continue;
        EnqueueEventTag58_021cf594(0x1130, i, 1);
    }
    return 0;
}
