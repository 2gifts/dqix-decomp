#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

struct FlagInner_021df6ec { char unk[0x14]; int flags; };
struct FlagObj_021df6ec { char unk[0x138]; struct FlagInner_021df6ec* inner; };
int IsFlagBit6Set_021df6ec(struct FlagObj_021df6ec* obj);

struct Ctx_021e9198 { char pad[0x10]; void* field0x10; };
struct Bits_021e9198 { unsigned short low6 : 6; unsigned short code : 3; unsigned short rest : 7; };

// USA: func_ov024_021e9198  (semantic: SelectMsgOrValue_021e9198)
extern "C" ARM int func_ov024_021e9198(struct Ctx_021e9198* ctx, int id, int code, int mode) {
	GameObject* c = GetCombatantByID((int)ctx->field0x10, id);
	if (!c) return 0;
	if (mode != 0) {
		if (!IsFlagBit6Set_021df6ec((struct FlagObj_021df6ec*)c)) goto ret0;
		struct Bits_021e9198* b = (struct Bits_021e9198*)((char*)c->currentStats_ + 0x22);
		if (b->code != code) goto ret0;
		switch (code) {
			case 1: return 0x26;
			case 2: return 0x140;
			case 3: return 0x126;
			case 4: return 0x13d;
			default: goto ret0;
		}
	}
	if (!IsFlagBit6Set_021df6ec((struct FlagObj_021df6ec*)c)) goto ret0;
	{
		struct Bits_021e9198* b = (struct Bits_021e9198*)((char*)c->currentStats_ + 0x22);
		if (b->code != code) goto ret0;
		switch (code) {
			case 1: return 0x27;
			case 2: return 0x141;
			case 3: return 0x137;
			case 4: return 0x13f;
			default: goto ret0;
		}
	}
ret0:
	return 0;
}
