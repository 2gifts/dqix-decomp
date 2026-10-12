#include <globaldefs.h>

#if defined(jpn)
enum { kCombatantFlagsOffset = 0x180 };
#else
enum { kCombatantFlagsOffset = 0x18c };
#endif


#if defined(jpn)
#define SetCombatantFlag8IfField8_021d25b8 func_ov017_021d2a3c
#endif
#include "GameState/GameState.h"


struct S021d25b8 { unsigned char pad0[4]; unsigned char field4; unsigned char pad1[3]; int field8; };

// USA: func_ov017_021d25b8
#if defined(jpn)
extern "C"
#endif
ARM void SetCombatantFlag8IfField8_021d25b8(int unused, S021d25b8* obj, GameState* battleStruct) {
	void* combatant = battleStruct->GetPartyMemberByIndex(obj->field4);
	if (!combatant) return;
	unsigned int* flags = (unsigned int*)((char*)combatant + kCombatantFlagsOffset);
	if (obj->field8 != 0) *flags |= 8;
	else *flags &= ~8;
}
