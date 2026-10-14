#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
struct FieldPtrObj_021f5228 { char pad[0x144]; char *ptr150; };
#else
struct FieldPtrObj_021f5228 { char pad[0x150]; char *ptr150; };
#endif
int GetFieldAt0x150_02053c6c(unsigned char* obj);
int GetTableByte020dd11c(unsigned int a, unsigned int b);

// USA: func_ov023_021f5228
ARM int CheckThresholdOverAny_021f5228(int id) {
#if defined(jpn)
 enum {regionalOffset0=0x8b8};
#else
 enum {regionalOffset0=0x950};
#endif
	GameState *bs = GameState::GetInstance();
	struct FieldPtrObj_021f5228 *combatant = (struct FieldPtrObj_021f5228*)GetCombatantWithFlag0x100_0200ff1c(bs, id);
	if (!combatant) return 0;
	int field150 = GetFieldAt0x150_02053c6c((unsigned char*)combatant);
	if (!field150) return 0;
	int val = *(int*)(combatant->ptr150 + regionalOffset0);
	unsigned int byteVal = val & 0xff;
	for (int i = 0; i < 5; i++) {
		int idx = GetTableByte020dd11c(byteVal, i & 0xff);
		unsigned char *base = (unsigned char*)(field150 + idx);
		if (base[0x464] < 0x64) return 1;
	}
	return 0;
}
