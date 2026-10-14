#include <globaldefs.h>
#include "GameState/GameState.h"

struct Vector3i;

// USA: func_ov017_021bd440
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
	*(Vector3i*)((int*)((char*)combatant + 0x44)) = *(Vector3i const*)((int*)(base + 0x184 + partyMemberIndex * 0xc));
	int savedRotationY = *(int*)(base + 0x1b4 + partyMemberIndex * 4);
#else
	*(Vector3i*)((int*)((char*)combatant + 0x44)) = *(Vector3i const*)((int*)(base + 0x188 + partyMemberIndex * 0xc));
	int savedRotationY = *(int*)(base + 0x1b8 + partyMemberIndex * 4);
#endif
	*(int*)((char*)combatant + 0x50) = 0;
	*(int*)((char*)combatant + 0x54) = savedRotationY;
	*(int*)((char*)combatant + 0x58) = 0;
}
