#include <globaldefs.h>

#if defined(jpn)
#define ApplyBuffIfEligible_021e5e80 func_ov024_021e6718
#endif
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

int CheckField0x14Bit0Clear02089160(unsigned char* obj);
void SetByte0x7cAndFlag0x800(unsigned char* obj);
extern "C" int func_ov000_0215e958(int a0);

struct FieldRefStruct_021e5e80 { char pad[0x10]; int field0x10; };

// USA: func_ov024_021e5e80
#if defined(jpn)
extern "C"
#endif
ARM void ApplyBuffIfEligible_021e5e80(struct FieldRefStruct_021e5e80* s, int id) {
	GameObject* c = GetCombatantByID(s->field0x10, id);
	if (!c) return;
	if (!CheckField0x14Bit0Clear02089160((unsigned char*)c->currentStats_)) return;
	if (!func_ov000_0215e958(s->field0x10)) return;
	SetByte0x7cAndFlag0x800((unsigned char*)c->currentStats_);
}
