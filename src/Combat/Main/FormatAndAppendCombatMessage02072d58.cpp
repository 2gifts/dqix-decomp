#include <globaldefs.h>
#if defined(jpn)
enum { kHeadTableOffset = 0x34ec, kIntrinsicOffset = 0x144 };
#else
enum { kHeadTableOffset = 0x36fc, kIntrinsicOffset = 0x150 };
#endif
#include "std_library_functions.h"
#include "GameState/GameState.h"

void FormatEffectStats02072c9c(int combatantId, char* buf);

struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

extern char data_020f0cff[];

// USA: func_02072d58
ARM void FormatAndAppendCombatMessage02072d58(int combatantId, char* statsBuf, char* outBuf) {
    FormatEffectStats02072c9c(combatantId, statsBuf);

    int base = ((int)func_ov017_0218b5b0());
    struct HeadNode02046b24** headTable = *(struct HeadNode02046b24***)((char*)base + kHeadTableOffset);
    int flag = 0;

    if (GetHeadNodeIdOrMinusOne(headTable) == 0xa) {
        GameObject* c = GameState::GetInstance()->GetCombatantByIndex(combatantId);
        if (c != NULL) {
            flag = *(unsigned char*)(*(int*)((char*)c + 0x138) + 0x26);
        }
    }

    if (flag != 0) {
        sprintf(outBuf, data_020f0cff, statsBuf, 0x62);
        sprintf(statsBuf, data_020f0cff, statsBuf, 0x66);
    } else {
        sprintf(statsBuf, data_020f0cff, statsBuf, 0x6e);
        sprintf(outBuf, data_020f0cff, statsBuf, 0x65);
    }

    GameObject* c2 = GetCombatantWithFlag0x100(GameState::GetInstance(), combatantId);
    if (c2 == NULL) {
        return;
    }

    int val = *(int*)((char*)c2 + kIntrinsicOffset);
    struct Flags02072d58 {
        unsigned char bit0 : 1;
        unsigned char rest : 7;
    };
    struct Flags02072d58* flagsField = (struct Flags02072d58*)(val + 0x49c);

    if (flagsField->bit0 == 1) {
        statsBuf[0] = 0x77;
    }
}
