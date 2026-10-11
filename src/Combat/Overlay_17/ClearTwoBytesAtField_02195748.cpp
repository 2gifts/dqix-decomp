#include <globaldefs.h>

#if defined(jpn)
struct S02195748 { char pad[0x16c]; unsigned char* p; };
#else
struct S02195748 { char pad[0x41c]; unsigned char* p; };
#endif

// USA: func_ov017_02195748
ARM void ClearTwoBytesAtField_02195748(unsigned char* base) {
	S02195748* s = (S02195748*)(base + 0x4000);
	unsigned char* p = s->p;
	p[0] = 0;
	p[1] = 0;
}
