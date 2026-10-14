#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
int HasFlagBit_0218d4ec(void* obj, int bit);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub021d25f4 {
    unsigned char field0;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char restBits : 6;
    unsigned char pad2[0xe];
};

struct EventBuf021d25f4 {
    unsigned char tag;
    unsigned char pad[3];
    struct Sub021d25f4 sub;
};

// USA: func_ov017_021d25f4  (semantic: SendCombatantFlagsEvent_021d25f4)
extern "C" ARM void func_ov017_021d25f4(int combatantId) {
    int handle = ((int)func_ov017_0218b5b0());
    void* p = GetData02100044_0202ae24();
    struct EventBuf021d25f4 buf;
    buf.tag = 0x20;
    struct Sub021d25f4* sub = &buf.sub;

    GameState* battle = GameState::GetInstance();
    if (battle == 0) return;
    GameObject* combatant = battle->GetPartyMemberByIndex(combatantId);
    if (combatant == 0) return;
    int val = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    if (val == 0) return;

    sub->field0 = (unsigned char)combatantId;
    sub->flag0 = *(unsigned char*)((char*)val + 0x56c);
    int hasFlag = HasFlagBit_0218d4ec((void*)handle, combatantId);
    sub->flag1 = (hasFlag != 0);

    func_0205e330(p, &buf, 0);
}
