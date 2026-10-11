#include <globaldefs.h>

struct S021b6b44 { unsigned char pad[0x24]; void* f24; };

extern "C" void func_ov003_021600b8(void*);

// USA: func_ov017_021b6b44
ARM void CallIfField24_021b6b44(S021b6b44* obj) {
	void* p = obj->f24;
	if (p) func_ov003_021600b8(p);
}
