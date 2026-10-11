#include <globaldefs.h>
#include "System/Memory.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum { kRegionValue14_10 = 0x10 };
enum { kRegionValue30_2C = 0x2c };
enum { kRegionValue31_2D = 0x2d };
enum { kRegionValue18_14 = 0x14 };
enum { kRegionValue34_30 = 0x30 };
enum { kRegionValue38_34 = 0x34 };
enum { kRegionValue3C_38 = 0x38 };
enum { kRegionValue90_8C = 0x8c };
enum { kRegionValue94_90 = 0x90 };
enum { kRegionValue98_94 = 0x94 };
enum { kRegionValue9C_98 = 0x98 };
enum { kRegionValueA0_9C = 0x9c };
enum { kRegionValueA4_A0 = 0xa0 };
enum { kRegionValueB8_B4 = 0xb4 };
enum { kRegionValueCC_C8 = 0xc8 };
#else
enum { kRegionValue14_10 = 0x14 };
enum { kRegionValue30_2C = 0x30 };
enum { kRegionValue31_2D = 0x31 };
enum { kRegionValue18_14 = 0x18 };
enum { kRegionValue34_30 = 0x34 };
enum { kRegionValue38_34 = 0x38 };
enum { kRegionValue3C_38 = 0x3c };
enum { kRegionValue90_8C = 0x90 };
enum { kRegionValue94_90 = 0x94 };
enum { kRegionValue98_94 = 0x98 };
enum { kRegionValue9C_98 = 0x9c };
enum { kRegionValueA0_9C = 0xa0 };
enum { kRegionValueA4_A0 = 0xa4 };
enum { kRegionValueB8_B4 = 0xb8 };
enum { kRegionValueCC_C8 = 0xcc };
#endif


void InitStruct0205a444(char* obj);
struct Struct020dfc40;
void ResetStruct020dfc40(struct Struct020dfc40* p);

// USA: func_ov003_0217daf0  (semantic: InitObject_0217daf0)
// JPN: func_ov003_0217c790
extern "C" ARM void func_ov003_0217daf0(char* obj) {
	*(int*)(obj + 0x0) = (*(volatile unsigned int*)0x4000000 & 0x1f00) >> 8;
	*(unsigned char*)(obj + 0x4) = 0;
	*(unsigned char*)(obj + 0x5) = 0;
	*(unsigned char*)(obj + 0x6) = 0;
	*(short*)(obj + 0x8) = 1;
	*(int*)(obj + 0xc) = 0;
	*(int*)(obj + kRegionValue14_10) = 0;
	*(unsigned char*)(obj + kRegionValue30_2C) = 0;
	*(unsigned char*)(obj + kRegionValue31_2D) = 0;
	VectorizedMemset(obj + kRegionValue18_14, 0, 0x18);
	*(int*)(obj + kRegionValue34_30) = 0;
	*(int*)(obj + kRegionValue38_34) = 0;
	InitStruct0205a444(obj + kRegionValue3C_38);
	*(int*)(obj + kRegionValue90_8C) = 0;
	*(int*)(obj + kRegionValue94_90) = 0;
	*(int*)(obj + kRegionValue98_94) = 0;
	*(int*)(obj + kRegionValue9C_98) = 0;
	*(int*)(obj + kRegionValueA0_9C) = 0;
	((SafeAllocator*)(obj + kRegionValueA4_A0))->ResetAllocatorPointer();
	((SafeAllocator*)(obj + kRegionValueB8_B4))->ResetAllocatorPointer();
	ResetStruct020dfc40((struct Struct020dfc40*)(obj + kRegionValueCC_C8));
}
