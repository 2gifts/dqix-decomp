#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

GameObject* GetCombatantWithFlag0x400ByID(int unused, int id);

static inline unsigned short GetMaxHP(GameObject* c) { unsigned short v = c->currentStats_->primaryStats.maxHP; return v; }
static inline unsigned short GetCurrHP(GameObject* c) { unsigned short v = c->currentStats_->primaryStats.currHP; return v; }

// USA: func_ov024_021f5888
extern "C" ARM int func_ov024_021f5888(int* p0, int id, int unused2, int* outFlag, void* out5) {
	GameObject* c = GetCombatantWithFlag0x400ByID(*p0, id);
	if (!c) return 0;
	if (GetCurrHP(c) >= GetMaxHP(c)) return 0;
	*outFlag = 0;
	memset(out5, -1, 8);
	return 1;
}
