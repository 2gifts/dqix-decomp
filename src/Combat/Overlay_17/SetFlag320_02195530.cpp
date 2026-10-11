#include <globaldefs.h>

#if defined(jpn)
#define FIELD_OFFSET 0x100
#else
#define FIELD_OFFSET 0x320
#endif

// USA: func_ov017_02195530
ARM void SetFlag320_02195530(unsigned char* obj) {
	obj += 0x4000;
	*(int*)(obj + FIELD_OFFSET) = 1;
}
