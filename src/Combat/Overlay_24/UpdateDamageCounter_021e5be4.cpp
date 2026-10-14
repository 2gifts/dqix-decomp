#include <globaldefs.h>
#include "GameState/GameState.h"

int IsIdOrEffectMatchTarget0215fd24(int unused, int id);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);

struct Ctx_021e5be4 { char pad[0x10]; void* field0x10; };
struct P2_021e5be4 { char pad[0x32]; short val0x32; };

// USA: func_ov024_021e5be4  (semantic: UpdateDamageCounter_021e5be4)
extern "C" ARM void func_ov024_021e5be4(struct Ctx_021e5be4* obj, int id, struct P2_021e5be4* p2, int unused3) {
	GameState* bs = GameState::GetInstance();
	void* field2a04 = GetPtrField0x2a04_02010828(bs);
	if (IsIdOrEffectMatchTarget0215fd24((int)obj->field0x10, id)) {
		*(int*)((char*)field2a04 + 0xf6c) -= p2->val0x32;
		return;
	}
	int base;
	int* arr;
	int idx;
	if (GetCombatantWithFlag0x1000_0200ff58(bs, id) != 0) {
		idx = 0;
		base = *(int*)((char*)obj->field0x10 + 0x8000 + 0xe84);
		arr = (int*)((char*)obj->field0x10 + 0x284 + 0x8c00);
	} else {
		arr = (int*)((char*)obj->field0x10 + 0x284 + 0x8c00);
		base = arr[id];
		idx = id;
	}
	arr[(short)idx] = base - p2->val0x32;
}
