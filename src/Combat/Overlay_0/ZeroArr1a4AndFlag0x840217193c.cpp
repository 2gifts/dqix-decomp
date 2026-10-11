#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xc4
#define REGION_OFFSET_1 0x1e4
#define REGION_OFFSET_2 0xc6
#else
#define REGION_OFFSET_0 0x84
#define REGION_OFFSET_1 0x1a4
#define REGION_OFFSET_2 0x86
#endif


struct Struct0217193c {
	unsigned char pad0[REGION_OFFSET_0];
	unsigned short f84;
	unsigned char pad1[REGION_OFFSET_1 - REGION_OFFSET_2];
	int arr1a4[0x93];
};

// USA: func_ov000_0217193c
ARM void ZeroArr1a4AndFlag0x840217193c(struct Struct0217193c* obj) {
	int i;
	for (i = 0; i < 0x93; i++) {
		obj->arr1a4[i] = 0;
	}
	obj->f84 = 0;
}
