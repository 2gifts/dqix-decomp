#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void func_020891cc(void* obj);

struct Ret021ca358 {
	unsigned char pad0[8];
	unsigned short field8;
	unsigned char pad1[0x30 - 0xa];
	int field30;
};

struct Src021ca358 {
	unsigned char pad0[4];
	unsigned short field4;
	unsigned char field6;
};

// JPN: func_ov017_021ca808
// USA: func_ov017_021ca358
ARM void CallHandlerEightTimesIfFieldsMatch_021ca358(int unused0, Src021ca358* src, int unused2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	void* h = *(void**)(obj + 0x3000 + regionalOffset0);
	Ret021ca358* r = (Ret021ca358*)func_ov017_021b8478(h);
	if (!r) return;
	if (r->field8 != src->field4) return;
	if (src->field6 != 0) {
		if (r->field30 == 0) return;
	}
	for (int i = 0; i < 8; i++) {
		func_020891cc((unsigned char*)r + 0x158 + i * 0xa4);
	}
}
