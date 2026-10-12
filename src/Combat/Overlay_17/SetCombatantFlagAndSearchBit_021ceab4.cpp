#include <globaldefs.h>

#if defined(jpn)
#define SetCombatantFlagAndSearchBit_021ceab4 func_ov017_021cef5c
#define SetFlag0x1ceBit0x10 func_02039830
#endif
#include "GameState/GameState.h"

struct SearchStruct;

#if defined(jpn)
extern "C"
#endif
void SetFlag0x1ceBit0x10(unsigned char* obj);
void SetSearchFlagBit0202c660(struct SearchStruct* obj, int value);

// USA: func_ov017_021ceab4
#if defined(jpn)
extern "C"
#endif
ARM void SetCombatantFlagAndSearchBit_021ceab4(int combatantId, int unused1, int unused2, int unused3, struct SearchStruct* search) {
	GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(combatantId);
	if (combatant != NULL) {
		SetFlag0x1ceBit0x10((unsigned char*)combatant);
	}
	SetSearchFlagBit0202c660(search, combatantId);
}
