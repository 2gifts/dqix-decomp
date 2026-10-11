#include <globaldefs.h>
#if defined(jpn)
enum { kRegion200 = 0x118 };
#else
enum { kRegion200 = 0x200 };
#endif
#include "std_library_functions.h"

struct BitfieldRecord020a1380;
void ResetBitfieldRecord(struct BitfieldRecord020a1380* rec);

struct Struct021580a0 {
	char pad0[4];
	void* field4;      // 0x4
	char pad1[4];
	char blockA[0x38]; // 0xc
	char blockB[kRegion200]; // 0x44
};

// JPN: func_ov003_0215958c
// USA: func_ov003_021580a0
ARM void InitBuffers_021580a0(struct Struct021580a0* p) {
	ResetBitfieldRecord((struct BitfieldRecord020a1380*)p);
	memset(p->blockA, 0, sizeof(p->blockA));
	memset(p->blockB, 0, sizeof(p->blockB));
	p->field4 = p->blockB;
}
