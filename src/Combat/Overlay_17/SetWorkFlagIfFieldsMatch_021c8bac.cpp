#include <globaldefs.h>

#if defined(jpn)
enum { kResourceWorkOffset = 0x3508 };
#else
enum { kResourceWorkOffset = 0x3718 };
#endif

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
void SetCombatWorkFlags0x55f4_ov000_02160fa8(void* work, int mask);

struct Ret021c8bac {
	unsigned char pad0[8];
	unsigned short field8;
};

struct Src021c8bac {
	unsigned char pad0[4];
	unsigned short field4;
};

// USA: func_ov017_021c8bac
ARM void SetWorkFlagIfFieldsMatch_021c8bac(int unused0, Src021c8bac* src, int unused2, unsigned char* obj) {
	unsigned char* h = *(unsigned char**)(obj + kResourceWorkOffset);
	if (h[2] == 0) return;
	Ret021c8bac* r = (Ret021c8bac*)func_ov017_021b8478(h);
	if (!r) return;
	if (r->field8 != src->field4) return;
	void* work = func_ov017_021b8468(h);
	if (!work) return;
	SetCombatWorkFlags0x55f4_ov000_02160fa8(work, 0x2000000);
}
