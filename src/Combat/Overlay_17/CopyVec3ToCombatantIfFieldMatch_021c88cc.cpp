#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Ret021c88cc {
	unsigned char pad0[8];
	unsigned short field8;
};

struct Src021c88cc {
	unsigned char pad0[4];
	int vec[3];
	short field10;
	unsigned short field12;
};

// JPN: func_ov017_021c8d7c
// USA: func_ov017_021c88cc
ARM void CopyVec3ToCombatantIfFieldMatch_021c88cc(int unused0, Src021c88cc* src, GameState* battleStruct, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	unsigned char* base = obj + 0x3000;
	void* h = *(void**)(base + regionalOffset0);
	Ret021c88cc* r = (Ret021c88cc*)func_ov017_021b8478(h);
	if (!r) return;
	if (!func_ov017_021b8468(h)) return;
	if (!GetField6b0_021b8470(h)) return;
	if (r->field8 != src->field12) return;
	GameObject* c = battleStruct->GetCombatantByIndex(src->field10);
	if (!c) return;
	int* dst = *(int**)((unsigned char*)c + 0x13c);
	if (!dst) return;
	_ZN8Vector3iaSERKS_((int*)((unsigned char*)dst + 0x10), src->vec);
}
