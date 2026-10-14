#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_02156b38(int a0, int id, unsigned int idx);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* battleStruct, int combatantId);

struct FlagsIdObj_021f875c { unsigned short flags; unsigned short pad2; short id; };
struct Params_021f875c { char pad0[0x8]; int field8; char pad1[0x4]; int field10; char pad2[0x4]; int field18; };
struct Inner144_021f875c { char pad[0xa]; unsigned short lowBits : 12; unsigned short flagBit12 : 1; };

// USA: func_ov024_021f875c  (semantic: DispatchByField18Shifted_021f875c)
extern "C" ARM int func_ov024_021f875c(int* obj0, struct FlagsIdObj_021f875c* obj1, struct Params_021f875c* obj2, int obj3) {
	GameState* bs = GameState::GetInstance();
	if (obj1->flags & 0x400) {
		GameObject* c = GetCombatantWithFlag0x400_0200fea4(bs, obj1->id);
		if (c && *(void**)((char*)c + 0x144)) {
			struct Inner144_021f875c* inner = *(struct Inner144_021f875c**)((char*)c + 0x144);
			if (inner->flagBit12) {
				if (!(obj2->field10 & 0x1000000)) {
					return 0;
				}
			}
		}
	}
	unsigned int idx;
	if (obj3 == 1) {
		idx = (unsigned int)obj2->field18 >> 27;
	} else {
		idx = (unsigned int)(obj2->field8 << 5) >> 27;
	}
	return func_ov000_02156b38(*obj0, obj1->id, idx);
}
