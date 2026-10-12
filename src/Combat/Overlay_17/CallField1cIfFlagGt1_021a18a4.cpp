#include <globaldefs.h>

struct Obj021e3184;
#if defined(jpn)
#define CallField1cIfFlagGt1_021a18a4 func_ov017_021a2334
#define func_ov023_021e3184 func_ov023_021e34dc
extern "C" void CallField1cIfFlagGt1_021a18a4(void*);
#endif
extern "C" void func_ov023_021e3184(Obj021e3184*);

// USA: func_ov017_021a18a4
ARM void CallField1cIfFlagGt1_021a18a4(void* obj) {
	unsigned char flag = *((unsigned char*)obj + 0x22);
	if (flag <= 1) return;
	void* p = *(void**)((char*)obj + 0x1c);
	if (!p) return;
	func_ov023_021e3184((Obj021e3184*)p);
}
