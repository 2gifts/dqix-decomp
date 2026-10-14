#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021d60f4(void*);
extern int AbsPlus159IfNegative0215ad2c(int x);
void ClearCombatantSlot_0200fd48(GameState* battleStruct, int id);
extern "C" void func_ov001_0215acb4(void* p);

struct GlobalTable_0215b9c4 { int pad0; unsigned char* elems; };
extern GlobalTable_0215b9c4 data_ov001_02165880;

struct Entry_0215b9c4 { int type; int field4; char pad8[8]; };

// USA: func_ov001_0215b9c4  (semantic: RemoveCombatantAndQueueEntries_0215b9c4)
extern "C" ARM int func_ov001_0215b9c4(void* self) {
	GameState* bs = GameState::GetInstance();
	if (bs == 0) return 0;
	int id = AbsPlus159IfNegative0215ad2c(func_ov017_021d60f4(self));
	GameObject* combatant = bs->GetGameObjectByIndex(id);
	if (combatant == 0) return 0;
	((Object3D*)((unsigned char*)combatant))->Destroy();
	ClearCombatantSlot_0200fd48(bs, id);
	if (data_ov001_02165880.elems != 0) {
		int i;
		for (i = 0; i < 0x20; i++) {
			unsigned char* base = data_ov001_02165880.elems;
			int type = *(int*)(base + i * 0x10);
			if (type == 1) {
				struct Entry_0215b9c4* e = (struct Entry_0215b9c4*)base + i;
				if (id == e->field4) {
					func_ov001_0215acb4((void*)e);
				}
			}
		}
	}
	return 1;
}
