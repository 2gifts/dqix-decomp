#include <globaldefs.h>
#include "GameState/GameState.h"

struct Src_021cc320 { unsigned char pad0[4]; unsigned char combatantId; };
struct S020535f4 { char pad[0x184]; unsigned char counter; };
void IncrementByteAt0x184(struct S020535f4* p);

// USA: func_ov017_021cc320
ARM void IncrementCombatantByteIfFlagSet_021cc320(void* unused0, Src_021cc320* src, GameState* battleStruct) {
	GameObject* c = GetCombatantWithFlag0x100_0200ff1c(battleStruct, src->combatantId);
	if (c != 0) {
		IncrementByteAt0x184((struct S020535f4*)c);
	}
}
