#include <globaldefs.h>

#if defined(jpn)
#define SetBitsFromByteList_021ccf70 func_ov017_021cd418
#endif
#include "GameState/GameState.h"

GameObject* GetCombatantWithFlag0x100(GameState* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
void SetBitInArray0x910(unsigned char* obj, int index);

struct Hdr021ccf70 {
	unsigned char id : 3;
	unsigned char count : 4;
	unsigned char pad : 1;
};

// USA: func_ov017_021ccf70
#if defined(jpn)
extern "C"
#endif
ARM void SetBitsFromByteList_021ccf70(int unused0, unsigned char* obj, GameState* battleStruct) {
	unsigned char* p = obj + 4;
	Hdr021ccf70* hdr = (Hdr021ccf70*)p;
	GameObject* c = GetCombatantWithFlag0x100(battleStruct, hdr->id);
	if (!c) return;

	unsigned char* base = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
	if (!base) return;

	for (int i = 0; i < hdr->count; i++) {
		unsigned char* pi = p + i;
		SetBitInArray0x910(base, pi[1]);
	}
}
