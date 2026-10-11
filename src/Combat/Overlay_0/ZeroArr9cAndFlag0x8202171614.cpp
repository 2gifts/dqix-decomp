#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xc2
#define REGION_OFFSET_1 0xdc
#define REGION_OFFSET_2 0xc4
#else
#define REGION_OFFSET_0 0x82
#define REGION_OFFSET_1 0x9c
#define REGION_OFFSET_2 0x84
#endif


struct Struct02171614 {
	unsigned char pad0[REGION_OFFSET_0];
	unsigned short f82;
	unsigned char pad1[REGION_OFFSET_1 - REGION_OFFSET_2];
	int arr9c[0x42];
};

// USA: func_ov000_02171614
ARM void ZeroArr9cAndFlag0x8202171614(struct Struct02171614* obj) {
	int i;
	for (i = 0; i < 0x42; i++) {
		obj->arr9c[i] = 0;
	}
	obj->f82 = 0;
}
