#if defined(jpn)
#define R(j,u) (j)
#define _Z22SetupBattleTag02189d68Pc func_ov012_0218a804
#define _Z35TestFlagsAndActiveElement2_021e6e20P11Obj021e6e20 func_ov023_021e7184
#define data_ov009_0218ac04 data_ov009_0218bb6c
#define data_ov013_02187d94 data_ov013_02188cd0
#define func_ov008_02187278 func_ov008_02188140
#define func_ov008_02187b20 func_ov008_021888fc
#define func_ov012_0218432c func_ov012_021853a0
#define func_ov012_0218930c func_ov012_02189be8
#define func_ov012_0218adac func_ov012_0218bba0
#define func_ov013_02185900 func_ov013_02186aec
#define func_ov023_021e6de4 func_ov023_021e7148
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void func_ov023_021dcba4(void* obj, int val);
extern "C" void func_ov023_021dcae0(void* obj, int val);

// USA: func_ov005_021551fc
ARM void DispatchByIdxAndCond021551fc(char* base, unsigned char byteVal, int cond) {
	signed char idx = *(signed char*)(base + 0x3d00 + R(0x33,0xbb));
	short val = *(short*)(base + idx * 0x1c + 0x2d00 + R(0x8,0x90));
	*(unsigned char*)(base + 0x1000 + R(0x936,0x9be)) = byteVal;
	unsigned short* flagPtr = (unsigned short*)(base + 0x1900 + R(0x30,0xb8));
	*flagPtr = *flagPtr | 0x80;
	if (cond != 0) {
		func_ov023_021dcba4(base + R(0x1240,0x1244), val);
	} else {
		func_ov023_021dcae0(base + R(0x1240,0x1244), val);
	}
}
