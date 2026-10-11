#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xc6
#define REGION_OFFSET_1 0x430
#define REGION_OFFSET_2 0xc7
#else
#define REGION_OFFSET_0 0x86
#define REGION_OFFSET_1 0x3f0
#define REGION_OFFSET_2 0x87
#endif


struct Struct02171b3c {
	unsigned char pad0[REGION_OFFSET_0];
	unsigned char f86;
	unsigned char pad1[REGION_OFFSET_1 - REGION_OFFSET_2];
	int arr3f0[0x10];
};

// USA: func_ov000_02171b3c
ARM void ZeroArr3f0AndFlag0x8602171b3c(struct Struct02171b3c* obj) {
	int i;
	for (i = 0; i < 0x10; i++) {
		obj->arr3f0[i] = 0;
	}
	obj->f86 = 0;
}
