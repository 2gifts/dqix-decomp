#include <globaldefs.h>

#if defined(jpn)
enum { FLAG_FIELD_OFFSET = 0xc6 };
#else
enum { FLAG_FIELD_OFFSET = 0x2e6 };
#endif

// USA: func_ov017_0219aa6c
ARM void SetFlag2e6_0219aa6c(unsigned char* obj) {
	obj += 0x4000;
	obj[FLAG_FIELD_OFFSET] = 1;
}
