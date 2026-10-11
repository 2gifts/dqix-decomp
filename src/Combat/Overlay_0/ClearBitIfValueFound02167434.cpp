#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x5ff0
#define REGION_OFFSET_1 0x5ff4
#define REGION_OFFSET_2 0x5ff1
#else
#define REGION_OFFSET_0 0x5e00
#define REGION_OFFSET_1 0x5e04
#define REGION_OFFSET_2 0x5e01
#endif


// USA: func_ov000_02167434
ARM void ClearBitIfValueFound02167434(unsigned char* obj, int value) {
	int i;
	for (i = 0; i < obj[REGION_OFFSET_0]; i++) {
		if (*(int*)(obj + REGION_OFFSET_1 + i * 4) == value) {
			obj[REGION_OFFSET_2] &= ~(1 << i);
			return;
		}
	}
}
