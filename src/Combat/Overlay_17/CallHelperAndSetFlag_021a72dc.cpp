#include <globaldefs.h>

struct S021a72dc { unsigned char f0; unsigned char f1; };

#if defined(jpn)
#define func_ov017_021a7280 func_ov017_021a7c28
#endif
extern "C" void func_ov017_021a7280(S021a72dc*);

// USA: func_ov017_021a72dc
ARM void CallHelperAndSetFlag_021a72dc(S021a72dc* obj) {
	func_ov017_021a7280(obj);
	obj->f1 = 1;
}
