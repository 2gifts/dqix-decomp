#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

extern "C" void func_ov023_021dcd90(void* p, int x);
extern "C" void func_ov006_02155508(void* s);
extern int data_0210a010[];

struct SubObj02155480 {
	char pad[0xe2];
	unsigned short flagsE2;
};

struct Obj02155480 {
	char pad0[LOW_REGION(0x880, 0xa00)];
	SubObj02155480 sub;
	char pad1000[0x1000 - (LOW_REGION(0x880, 0xa00) + sizeof(SubObj02155480))];
	char pad2bd[LOW_REGION(0xb9, 0x2bd)];
	unsigned char flag2bd;
};

// USA: func_ov006_02155480
ARM void ResetDisplayState02155480(Obj02155480* o) {
	o->flag2bd = 1;
	*(unsigned int*)((char*)data_0210a010 + 0xa0) = 0xbfff0000;

	volatile unsigned short* reg = (volatile unsigned short*)0x4000008;
	reg[0] = (reg[0] & ~3) | 2;
	reg[1] = (reg[1] & ~3);
	reg[2] = (reg[2] & ~3) | 1;

	o->sub.flagsE2 &= ~0x40;

	func_ov023_021dcd90((char*)o + LOW_REGION(0x164, 0x2e4) + 0x800, 0);
	func_ov006_02155508(o);
}
