#include <globaldefs.h>
#include "GameState/GameState.h"

struct Ent021ce658 {
	char pad0[4];
	signed char f4;
	signed char f5;
	unsigned char f6;
};

GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
void InitAndRequeueEntry020e3b8c(char* mgr, int index, int p3, int p4, int p5, int p6, int p7, unsigned char p8);

// JPN: func_ov017_021ceb00
// USA: func_ov017_021ce658  (semantic: RequeueEntryForCombatant_021ce658)
extern "C" ARM void func_ov017_021ce658(void* unused0, struct Ent021ce658* entry, GameState* battle, char* mgr) {
#if defined(jpn)
 enum {regionalOffset0=0x8b8};
#else
 enum {regionalOffset0=0x950};
#endif
	signed char f4 = entry->f4;
	GameObject* c = GetCombatantWithFlag0x100(battle, f4);
	if (c == NULL) return;

	char* field150 = (char*)GetFieldAt0x150((unsigned char*)c);
	if (field150 == 0) return;

	int field950 = *(int*)(field150 + regionalOffset0);
	signed char f5 = entry->f5;
	unsigned short halfword = *(unsigned short*)(field150 + (field950 << 1) + 0x100 + 0x6c);
	if (f5 < 0) return;

	if (f5 == 0) {
		InitAndRequeueEntry020e3b8c(mgr, f4, halfword, field950, 0, 0, 0, entry->f6);
	} else {
		InitAndRequeueEntry020e3b8c(mgr, f4, f5, field950, 0, 0, 0, entry->f6);
	}
}
