#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_ov017_021d6134(void*, int);
int CopyIndexedRegion0x75f0_020ac020(void* unused, short* indices, int* dest, int count);

struct PackedBits_021eae38 {
	unsigned int f0 : 10;
	unsigned int f1 : 1;
	unsigned int f2 : 7;
	unsigned int f3 : 7;
	unsigned int reserved : 7;
};

union PackedUnion_021eae38 {
	struct PackedBits_021eae38 bits;
	int raw;
};

// USA: func_ov023_021eae38
ARM int PackAndForward_021eae38(void *obj) {
	short indices[1];
	union PackedUnion_021eae38 dest;
	dest.bits.f0 = 0;
	dest.bits.f1 = 0;
	dest.bits.f2 = 0;
	dest.bits.f3 = 0;
	indices[0] = (short)func_ov017_021d60f4(obj);
	CopyIndexedRegion0x75f0_020ac020(0, indices, &dest.raw, 1);
	func_ov017_021d6134((char*)obj + 8, (int)dest.bits.f0);
	return 1;
}
