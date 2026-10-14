#include <globaldefs.h>
#include "GameState/GameState.h"

struct TagInfo_021d26a4 {
    unsigned char pad[4];
    unsigned char id;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
};

int GetFieldAt0x150_02053c6c(unsigned char* obj);
void SetFlagBit_0218d4b8(unsigned char* base, int bit);
void ClearFlagBit_0218d4d0(void* obj, int bit);
extern "C" void func_ov017_02191aac(void* obj, int mode, int idx, unsigned char mask);

// USA: func_ov017_021d26a4  (semantic: SetCombatantField150FlagAndNotify)
extern "C" ARM void func_ov017_021d26a4(void* unused, TagInfo_021d26a4* info, GameState* battleStruct, void* base) {
    int flagBase = ((int)func_ov017_0218b5b0());
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(info->id);
    if (combatant == 0) {
        return;
    }
    unsigned char* field150 = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    if (field150 == 0) {
        return;
    }
    bool bit0 = info->flag0;
    field150[0x56c] = bit0;
    if (field150[0x56c]) {
        func_ov017_02191aac(base, 1, info->id, 2);
    }
    if (info->flag1) {
        SetFlagBit_0218d4b8((unsigned char*)flagBase, info->id);
    } else {
        ClearFlagBit_0218d4d0((void*)flagBase, info->id);
    }
}
