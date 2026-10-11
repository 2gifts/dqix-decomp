#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0xe24
#define REGION_OFFSET_1 0xe28
#else
#define REGION_OFFSET_0 0xea8
#define REGION_OFFSET_1 0xeac
#endif


extern int data_ov000_02184220;

// USA: func_ov000_02160d80
ARM void SetFieldsAndSignalData02184220(void* p, int val) {
	*(int*)((char*)p + REGION_OFFSET_0) = val;
	*(int*)((char*)p + REGION_OFFSET_1) = 0;
	data_ov000_02184220 = 1;
}
