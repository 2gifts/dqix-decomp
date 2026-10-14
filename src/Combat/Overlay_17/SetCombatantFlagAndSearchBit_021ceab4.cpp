#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct;

void SetFlag0x1ceBit0x10_02039dd8(unsigned char* obj);
void SetSearchFlagBit0202c660(struct SearchStruct* obj, int value);

// USA: func_ov017_021ceab4
ARM void SetCombatantFlagAndSearchBit_021ceab4(int combatantId, int unused1, int unused2, int unused3, struct SearchStruct* search) {
	GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(combatantId);
	if (combatant != NULL) {
		SetFlag0x1ceBit0x10_02039dd8((unsigned char*)combatant);
	}
	SetSearchFlagBit0202c660(search, combatantId);
}
