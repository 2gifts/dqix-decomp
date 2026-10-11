#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e3134 func_ov023_021e348c
#endif

extern "C" void func_ov023_021e3134(void*);

// USA: func_ov017_021a1880
ARM void CallField1cIfFlagGt1_021a1880(void* obj) {
	unsigned char flag = *((unsigned char*)obj + 0x22);
	if (flag <= 1) return;
	void* p = *(void**)((char*)obj + 0x1c);
	if (!p) return;
	func_ov023_021e3134(p);
}
