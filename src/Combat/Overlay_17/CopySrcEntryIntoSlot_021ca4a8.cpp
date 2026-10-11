#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
int GetField0x3acValue(GameState* battleStruct);

struct SrcEntry021ca4a8 {
	char pad0[4];
	unsigned short field4;
	unsigned short field6;
	unsigned short field8;
	unsigned short fielda;
	int fieldc;
	int field10;
};

// JPN: func_ov017_021ca958
// USA: func_ov017_021ca4a8
ARM void CopySrcEntryIntoSlot_021ca4a8(int unused0, struct SrcEntry021ca4a8* src, GameState* battleStruct, unsigned char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	void* table = *(void**)(base + 0x3000 + regionalOffset0);
	unsigned char* obj = (unsigned char*)func_ov017_021b8478(table);
	if (obj == NULL) {
		return;
	}
	if (*(signed char*)(obj + 0x2a) == GetField0x3acValue(battleStruct)) {
		return;
	}
	if (*(unsigned short*)(obj + 8) != src->field4) {
		return;
	}
	int idx = src->field6 - 0xc0;
	if (idx < 0) {
		return;
	}
	if (idx >= 8) {
		return;
	}
	unsigned char* entry = obj + 0x158 + idx * 0xa4;
	*(unsigned short*)(entry + 0) = src->field8;
	*(unsigned short*)(entry + 2) = src->fielda;
	*(int*)(entry + 0x14) = src->fieldc;
	*(int*)(entry + 0x18) = src->field10;
}
