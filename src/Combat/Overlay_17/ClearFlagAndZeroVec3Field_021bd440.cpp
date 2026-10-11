#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// If the selected bit was set, copies the stored position and Y rotation to
// the party member, while setting rotation X and Z to zero. The writer of
// the stored values has not been identified here.
// USA: func_ov017_021bd440
// JPN: func_ov017_021bda38
ARM void ClearFlagAndZeroVec3Field_021bd440(void* self, int partyMemberIndex) {
	unsigned char* base = (unsigned char*)self;
	unsigned char partyMemberMask = 1 << partyMemberIndex;
	int wasRestoreBitSet = 0;
#if defined(jpn)
	if (base[0x170] & partyMemberMask) wasRestoreBitSet = 1;
	base[0x170] &= ~partyMemberMask;
	base[0x171] |= partyMemberMask;
#else
	if (base[0x174] & partyMemberMask) wasRestoreBitSet = 1;
	base[0x174] &= ~partyMemberMask;
	base[0x175] |= partyMemberMask;
#endif
	if (!wasRestoreBitSet) return;
	GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(partyMemberIndex);
	if (!combatant) return;
#if defined(jpn)
	_ZN8Vector3iaSERKS_((int*)((char*)combatant + 0x44), (int*)(base + 0x184 + partyMemberIndex * 0xc));
	int savedRotationY = *(int*)(base + 0x1b4 + partyMemberIndex * 4);
#else
	_ZN8Vector3iaSERKS_((int*)((char*)combatant + 0x44), (int*)(base + 0x188 + partyMemberIndex * 0xc));
	int savedRotationY = *(int*)(base + 0x1b8 + partyMemberIndex * 4);
#endif
	*(int*)((char*)combatant + 0x50) = 0;
	*(int*)((char*)combatant + 0x54) = savedRotationY;
	*(int*)((char*)combatant + 0x58) = 0;
}
