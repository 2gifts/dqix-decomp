#include <globaldefs.h>

#if defined(jpn)
#define func_ov024_021e4588 func_ov024_021e4e20
#endif
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct FlagObj_021de25c;
int IsFlagBit5Set_021de25c(struct FlagObj_021de25c* obj);
void ClearFlag0x20AndBytes(void* obj);
extern "C" void func_ov000_02159eac(void* a0, void* buf, int a2);

struct Obj_021e4588 { char pad[0x10]; void* field0x10; };
struct StatsByte0x3b_021e4588 { char pad[0x3b]; unsigned char b; };

// USA: func_ov024_021e4588  (semantic: SetLowBitAndNotify_021e4588)
extern "C" ARM unsigned long long func_ov024_021e4588(struct Obj_021e4588* obj, int unused, int id) {
	GameObject* c = GetCombatantByID((int)obj->field0x10, id);
	if (!c) return 0;
	union { struct { int lo; int hi; }; unsigned long long v; } local;
	local.lo = 0;
	local.hi = 0;
	if (IsFlagBit5Set_021de25c((struct FlagObj_021de25c*)c)) {
		ClearFlag0x20AndBytes(c->currentStats_);
		struct StatsByte0x3b_021e4588* s = (struct StatsByte0x3b_021e4588*)c->currentStats_;
		s->b = (s->b & ~1) | 1;
		func_ov000_02159eac(obj->field0x10, &local, 0x19);
	}
	return local.v;
}
