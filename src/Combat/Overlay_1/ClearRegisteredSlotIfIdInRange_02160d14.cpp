#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
extern int AbsPlus159IfNegative0215ad2c(int x);
extern void* GetGlobalPtr021075f4_0203cf4c(void);
void* FindEntryPointerByKey0203df78(void* base, int key);
void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id);

struct FlagD4Struct_02160d14 {
    unsigned char pad[0xd4];
    unsigned char flagBit0 : 1;
};

// USA: func_ov001_02160d14  (semantic: ClearRegisteredSlotIfIdInRange_02160d14)
extern "C" ARM int func_ov001_02160d14(char* self) {
    GameState* bs = GameState::GetInstance();
    void* global = GetGlobalPtr021075f4_0203cf4c();
    int id1 = func_ov017_021d60f4(self);
    int id2 = AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4(self + 0x8));
    if (id2 < 0xa0 || id2 > 0xbf) return 0;
    void* entry = FindEntryPointerByKey0203df78(global, id1);
    if (entry == 0) return 0;
    struct FlagD4Struct_02160d14* combatant = *(struct FlagD4Struct_02160d14**)((char*)entry + 0x18);
    if (combatant == 0) return 0;
    combatant->flagBit0 = 0;
    ClearCombatantSlot_0200fd48(bs, id2);
    return 1;
}
