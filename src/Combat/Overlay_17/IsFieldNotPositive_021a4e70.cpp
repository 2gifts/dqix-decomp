#include <globaldefs.h>

#if defined(jpn)
struct S021a4e70 { char pad[0x34]; signed char field; };
#else
struct S021a4e70 { char pad[0x54]; signed char field; };
#endif

// USA: func_ov017_021a4e70
ARM int IsFieldNotPositive_021a4e70(unsigned char* base) {
#if defined(jpn)
	S021a4e70* s = (S021a4e70*)(base + 0x4100);
#else
	S021a4e70* s = (S021a4e70*)(base + 0x4300);
#endif
	return s->field <= 0;
}
