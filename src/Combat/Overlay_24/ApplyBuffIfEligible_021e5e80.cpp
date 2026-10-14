#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/Overlay_0/GetCombatantByID.h"

int CheckField0x14Bit0Clear02089160(unsigned char* obj);
void SetByte0x7cAndFlag0x800_02089174(unsigned char* obj);
extern "C" int func_ov000_0215e958(int a0);

struct FieldRefStruct_021e5e80 { char pad[0x10]; int field0x10; };

// USA: func_ov024_021e5e80
ARM void ApplyBuffIfEligible_021e5e80(struct FieldRefStruct_021e5e80* s, int id) {
	GameObject* c = GetCombatantByID(s->field0x10, id);
	if (!c) return;
	if (!CheckField0x14Bit0Clear02089160((unsigned char*)c->currentStats_)) return;
	if (!func_ov000_0215e958(s->field0x10)) return;
	SetByte0x7cAndFlag0x800_02089174((unsigned char*)c->currentStats_);
}
