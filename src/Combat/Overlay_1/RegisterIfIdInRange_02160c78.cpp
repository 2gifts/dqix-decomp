#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
extern int AbsPlus159IfNegative0215ad2c(int x);
extern void* GetGlobalPtr021075f4_0203cf4c(void);
void* FindEntryPointerByKey0203df78(void* base, int key);
void RegisterCombatantSlot_0200fd38(GameState* battleStruct, int id, GameObject* combatant);

struct FlagD4Struct_02160c78 {
	unsigned char pad[0xd4];
	unsigned char flagBit0 : 1;
};

// USA: func_ov001_02160c78  (semantic: RegisterIfIdInRange_02160c78)
extern "C" ARM int func_ov001_02160c78(char* self) {
	GameState* bs = GameState::GetInstance();
	void* global = GetGlobalPtr021075f4_0203cf4c();
	int id1 = func_ov017_021d60f4(self);
	int id2 = AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4(self + 0x8));
	if (id2 < 0xa0 || id2 > 0xbf) return 0;
	void* entry = FindEntryPointerByKey0203df78(global, id1);
	if (entry == 0) return 0;
	struct FlagD4Struct_02160c78* combatant = *(struct FlagD4Struct_02160c78**)((char*)entry + 0x18);
	if (combatant == 0) return 0;
	combatant->flagBit0 = 1;
	RegisterCombatantSlot_0200fd38(bs, id2, *(GameObject**)((char*)entry + 0x18));
	return 1;
}
