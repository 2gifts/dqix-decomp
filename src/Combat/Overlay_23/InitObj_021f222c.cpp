#include <globaldefs.h>
#include "std_library_functions.h"

struct Bits_021f222c {
	unsigned int f0 : 9;
	unsigned int f1 : 9;
	unsigned int f2 : 9;
	unsigned int f3 : 3;
	unsigned int f4 : 2;
};

union Word_021f222c {
	struct Bits_021f222c bits;
	unsigned int raw;
};

struct Obj_021f222c {
	union Word_021f222c word0;
	void *field4;
	int field8;
	char blockC[0x38];
#if defined(jpn)
	char field44[0x118];
#else
	char field44[0x200];
#endif
};

// JPN: func_ov023_021f1afc
// USA: func_ov023_021f222c
ARM void InitObj_021f222c(struct Obj_021f222c *obj) {
	obj->word0.bits.f0 = 0;
	obj->word0.bits.f1 = 0;
	obj->word0.bits.f2 = 0;
	obj->word0.bits.f3 = 0;
	obj->word0.bits.f4 = 0;
	obj->field4 = 0;
	obj->field8 = 0;
	memset(obj->blockC, 0, sizeof(obj->blockC));
	memset(obj->field44, 0, sizeof(obj->field44));
	obj->field4 = obj->field44;
}
