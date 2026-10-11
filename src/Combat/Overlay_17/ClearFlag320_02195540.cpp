#include <globaldefs.h>

#if defined(jpn)
#define FIELD_OFFSET 0x100
#else
#define FIELD_OFFSET 0x320
#endif

// JPN: func_ov017_02196108
// USA: func_ov017_02195540
ARM void ClearFlag320_02195540(unsigned char* obj) {
	obj += 0x4000;
	*(int*)(obj + FIELD_OFFSET) = 0;
}
