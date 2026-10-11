#include <globaldefs.h>

struct S021a6b84 { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021a6b30(S021a6b84*);

// USA: func_ov017_021a6b84
ARM void CallHelperAndSetFlag_021a6b84(S021a6b84* obj) {
	func_ov017_021a6b30(obj);
	obj->f1 = 1;
}
