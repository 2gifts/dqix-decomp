#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
void* GetField6b0_021b8470(void* obj);
int GetField0x3acValue(GameState* battleStruct);

struct Src021c840c {
	unsigned char pad0[4];
	unsigned short field4;
	unsigned char field6;
	unsigned char pad1;
	int field8;
};

struct Ret021c840c {
	unsigned char pad0[5];
	unsigned char field5;
	unsigned char pad1[2];
	unsigned short field8;
	unsigned char pad2[0x20];
	signed char field2a;
};

// JPN: func_ov017_021c88bc
// USA: func_ov017_021c840c
ARM void UpdateFieldIfHalfwordsMatch_021c840c(int unused0, Src021c840c* src, GameState* battleStruct, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	unsigned char* base = obj + 0x3000;
	void* h = *(void**)(base + regionalOffset0);
	Ret021c840c* r = (Ret021c840c*)func_ov017_021b8478(h);
	if (!r) return;
	void* work = GetField6b0_021b8470(h);
	if (!work) return;
	int val = GetField0x3acValue(battleStruct);
	if (r->field2a == val) return;
	if (r->field8 == src->field4) {
		*(int*)((unsigned char*)work + 0x8000 + 0xe20) = src->field8;
		r->field5 = src->field6;
	}
}
