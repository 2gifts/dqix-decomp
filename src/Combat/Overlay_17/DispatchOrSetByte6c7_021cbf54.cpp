#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
unsigned short GetField6b4_021b8480(void* obj);
void EnqueueEventTag128_021cbf18(unsigned char a, unsigned short b);

struct Ret021cbf54 {
	unsigned char pad0[8];
	unsigned short field8;
};

struct Src021cbf54 {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char pad1;
	unsigned short field6;
};

// JPN: func_ov017_021cc404
// USA: func_ov017_021cbf54
ARM void DispatchOrSetByte6c7_021cbf54(int unused0, Src021cbf54* src, int unused2, unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x508};
#else
 enum {regionalOffset0=0x718};
#endif
	unsigned char* h = *(unsigned char**)(obj + 0x3000 + regionalOffset0);
	Ret021cbf54* r = (Ret021cbf54*)func_ov017_021b8478(h);
	if (r->field8 != src->field6) return;
	if (src->field4 == 0) {
		if (GetField6b4_021b8480(h) == 2) return;
		EnqueueEventTag128_021cbf18(1, src->field6);
	} else {
		if (src->field4 == 1) {
			*(unsigned char*)(h + 0x6c7) = 2;
		}
	}
}
