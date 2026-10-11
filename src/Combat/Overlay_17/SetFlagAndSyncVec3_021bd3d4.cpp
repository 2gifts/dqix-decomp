#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// JPN: func_ov017_021bd9cc
// USA: func_ov017_021bd3d4
ARM void SetFlagAndSyncVec3_021bd3d4(void* self, int index) {
#if defined(jpn)
 enum {regionalOffset0=0x170, regionalOffset1=0x171, regionalOffset2=0x184, regionalOffset3=0x1b4};
#else
 enum {regionalOffset0=0x174, regionalOffset1=0x175, regionalOffset2=0x188, regionalOffset3=0x1b8};
#endif
	unsigned char* base = (unsigned char*)self;
	unsigned char mask = 1 << index;
	base[regionalOffset0] |= mask;
	base[regionalOffset1] &= ~mask;
	GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(index);
	if (combatant) {
		_ZN8Vector3iaSERKS_((int*)(base + regionalOffset2 + index * 0xc), (int*)((char*)combatant + 0x44));
		*(int*)(base + regionalOffset3 + index * 4) = *(int*)((char*)combatant + 0x54);
	}
}
