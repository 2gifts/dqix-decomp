#include <globaldefs.h>
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
int GetFieldAt0x150_02053c6c(unsigned char* obj);

struct Src021ccd10 {
	unsigned char id : 3;
	unsigned char mode : 1;
	unsigned char pad : 4;
	unsigned char bytes[15];
};

// USA: func_ov017_021ccd10  (semantic: CopyBytesIntoField150ByMode_021ccd10)
extern "C" ARM void func_ov017_021ccd10(int unused0, char* p1raw, GameState* battleStruct) {
	struct Src021ccd10* p1 = (struct Src021ccd10*)(p1raw + 4);
	GameObject* c = GetCombatantWithFlag0x100_0200ff1c(battleStruct, p1->id);
	if (!c) return;

	unsigned char* dst = (unsigned char*)GetFieldAt0x150_02053c6c((unsigned char*)c);
	if (!dst) return;

	if (!p1->mode) {
		for (int i = 0; i < 15; i++) {
			unsigned char* slot = dst + i;
			slot[0x464] = p1->bytes[i];
		}
	} else {
		if (p1->mode == 1) {
			for (int i = 0; i < 12; i++) {
				int idx = i + 0xf;
				unsigned char* slot = dst + idx;
				slot[0x464] = p1->bytes[i];
			}
		}
	}
}
