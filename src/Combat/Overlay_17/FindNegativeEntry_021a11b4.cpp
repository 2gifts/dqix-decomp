#include <globaldefs.h>

struct Entry021a11b4 { short val; unsigned char pad[0x5ec - 2]; };
struct S021a11b4 {
#if defined(jpn)
    unsigned char pad[0xb8];
#else
    unsigned char pad[0x2c8];
#endif
 unsigned char pad2[0x1000]; Entry021a11b4 arr[4]; };

// USA: func_ov017_021a11b4
ARM void* FindNegativeEntry_021a11b4(S021a11b4* base) {
	for (int i = 0; i < 4; i++) {
		if (base->arr[i].val < 0) return &base->arr[i];
	}
	return 0;
}
