#include <globaldefs.h>

#if defined(jpn)
#define SetBitsFromRange16_021cd1ac func_ov017_021cd654
#endif
#include "GameState/GameState.h"

int GetFieldAt0x150(unsigned char* obj);
void SetBitInArray0x8ec(unsigned char* obj, int index);
extern "C" void func_02083e28(void* a, int arg2);

struct Hdr021cd1ac {
	unsigned char id : 3;
	unsigned char count : 3;
	unsigned char pad : 2;
};

// USA: func_ov017_021cd1ac
#if defined(jpn)
extern "C"
#endif
ARM void SetBitsFromRange16_021cd1ac(int unused0, unsigned char* obj, GameState* battleStruct) {
	unsigned char* p = obj + 4;
	Hdr021cd1ac* hdr = (Hdr021cd1ac*)p;
	GameObject* c = GetCombatantWithFlag0x100(battleStruct, hdr->id);
	if (!c) return;
	unsigned char* base = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
	if (!base) return;
	for (int i = 0; i < hdr->count; i++) {
		unsigned short v = *(unsigned short*)(p + i * 2 + 2);
		SetBitInArray0x8ec(base, v);
	}
	func_02083e28(base, 0);
}
