#include <globaldefs.h>

struct S021b83f0 { unsigned char f0; unsigned char f1; };

extern "C" void func_ov017_021b6f9c(S021b83f0*);

// USA: func_ov017_021b83f0
ARM void CallHelperAndSetFlag_021b83f0(S021b83f0* obj) {
	func_ov017_021b6f9c(obj);
	obj->f1 = 1;
}
