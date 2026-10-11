#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e3084 func_ov023_021e33dc
#endif

struct S_021a185c { unsigned char pad0[0x1c]; void* ptr; unsigned char pad2[0x22 - 0x1c - 4]; unsigned char flag; };

extern "C" void func_ov023_021e3084(void*);

// USA: func_ov017_021a185c
ARM void CallHelperIfByteAboveOneAndPtrSet_021a185c(S_021a185c* obj) {
	if (obj->flag <= 1) {
		return;
	}
	if (obj->ptr == 0) {
		return;
	}
	func_ov023_021e3084(obj->ptr);
}
