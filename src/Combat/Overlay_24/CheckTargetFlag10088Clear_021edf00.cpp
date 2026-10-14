#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

GameObject* GetCombatantWithFlag0x400ByID_ov000_021536f8(int unused, int id);

struct FlagInner_021e05e4 { char unk[0x18]; int flags; };
struct FlagObj_021e05e4 { char unk[0x138]; struct FlagInner_021e05e4* inner; };
int IsFlagBit12Field18Set_021e05e4(struct FlagObj_021e05e4* obj);

struct S_10088_inner { char unk[0x14]; int flags; };
struct S_10088 { char unk[0x138]; struct S_10088_inner* inner; };
int IsFlag10088Set_02010088(struct S_10088* obj);

// USA: func_ov024_021edf00  (semantic: CheckTargetFlag10088Clear_021edf00)
extern "C" ARM int func_ov024_021edf00(int* a0, int a1, short* a2) {
	GameObject* c = (GameObject*)GetCombatantWithFlag0x400ByID_ov000_021536f8(*a0, a1);
	if (!c) return 0;
	if (!IsFlagBit12Field18Set_021e05e4((struct FlagObj_021e05e4*)c)) return 0;
	short targetId = *(short*)((char*)c->currentStats_ + 0x2e);
	GameObject* c2 = GetCombatantByID(*a0, targetId);
	if (!c2) goto fail;
	if (!IsFlag10088Set_02010088((struct S_10088*)c2)) {
		*a2 = *(short*)((char*)c->currentStats_ + 0x2e);
		return 1;
	}
fail:
	return 0;
}
