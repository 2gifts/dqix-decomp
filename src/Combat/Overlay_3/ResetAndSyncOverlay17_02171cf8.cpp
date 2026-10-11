#include <globaldefs.h>

#if defined(jpn)
enum { kRegionValue730_62C = 0x62c };
enum { kRegionValue3B48_3928 = 0x3928 };
enum { kRegionValue36FC_34EC = 0x34ec };
enum { kRegionValue4494_41E4 = 0x41e4 };
#else
enum { kRegionValue730_62C = 0x730 };
enum { kRegionValue3B48_3928 = 0x3b48 };
enum { kRegionValue36FC_34EC = 0x36fc };
enum { kRegionValue4494_41E4 = 0x4494 };
#endif


extern "C" char* func_ov017_0218b5b0();
extern "C" void func_ov017_021b1e24(void* a, void* b);

struct S02171cf8 {
	unsigned char flag0;
	char pad1[kRegionValue730_62C - 0x1];
	unsigned char flag730;
	unsigned char flag731;
	unsigned char flag732;
	unsigned char flag733;
};

// USA: func_ov003_02171cf8
// JPN: func_ov003_02170fb4
ARM void ResetAndSyncOverlay17_02171cf8(struct S02171cf8* obj) {
	char* base = func_ov017_0218b5b0();
	char* p = *(char**)(base + kRegionValue3B48_3928);
	char* q = *(char**)(base + kRegionValue36FC_34EC);
	func_ov017_021b1e24(p, q);
	if (*(int*)(base + kRegionValue4494_41E4) != 0) return;
	if (((unsigned char*)p)[0x28] != 0) {
		obj->flag730 &= ~0x2;
		obj->flag733 = 1;
	}
	base = func_ov017_0218b5b0();
	*(int*)(base + kRegionValue4494_41E4) = 1;
	obj->flag0 = 0;
	obj->flag731 = 2;
	obj->flag732 = 3;
}
