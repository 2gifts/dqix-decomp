#include <globaldefs.h>

#if defined(jpn)
#define FIELD_OFFSET 0x448
#else
#define FIELD_OFFSET 0x658
#endif

// USA: func_ov017_0219aa5c
ARM void ClearFlag658_0219aa5c(unsigned char* obj) {
	obj += 0x3000;
	obj[FIELD_OFFSET] = 0;
}
