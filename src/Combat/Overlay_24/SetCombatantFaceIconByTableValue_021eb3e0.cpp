#include <globaldefs.h>
#include "GameState/GameState.h"

unsigned short GetTableValue_0202053c(void* obj);

struct StatsByte0x3b_021eb3e0 {
	char unk[0x3b];
	unsigned char byte0x3b_lo : 4;
	unsigned char byte0x3b : 4;
};

// USA: func_ov024_021eb3e0  (semantic: SetCombatantFaceIconByTableValue_021eb3e0)
extern "C" ARM void func_ov024_021eb3e0(void* unused, int combatantId) {
	GameState* battle = GameState::GetInstance();
	GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(battle, combatantId);
	if (combatant == NULL) {
		return;
	}
	struct StatsByte0x3b_021eb3e0* stats;
	unsigned short value = GetTableValue_0202053c(combatant);
	if (value >= 0x4b) {
		stats = (struct StatsByte0x3b_021eb3e0*)combatant->currentStats_;
		stats->byte0x3b = 0xa;
		return;
	}
	value = GetTableValue_0202053c(combatant);
	if (value >= 0x32) {
		stats = (struct StatsByte0x3b_021eb3e0*)combatant->currentStats_;
		stats->byte0x3b = 0x9;
		return;
	}
	value = GetTableValue_0202053c(combatant);
	if (value >= 0x19) {
		stats = (struct StatsByte0x3b_021eb3e0*)combatant->currentStats_;
		stats->byte0x3b = 0x8;
	} else {
		stats = (struct StatsByte0x3b_021eb3e0*)combatant->currentStats_;
		stats->byte0x3b = 0x7;
	}
}
