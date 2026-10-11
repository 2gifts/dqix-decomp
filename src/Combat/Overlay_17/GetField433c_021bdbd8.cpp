#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD 0x11c
#else
#define REGION_FIELD 0x33c
#endif

struct S021bdbd8 { char pad[REGION_FIELD]; int value; };

// USA: func_ov017_021bdbd8
ARM int GetField433c_021bdbd8(unsigned char* base) {
	S021bdbd8* s = (S021bdbd8*)(base + 0x4000);
	return s->value;
}
