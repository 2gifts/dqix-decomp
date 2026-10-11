#include <globaldefs.h>

struct S021b6b5c { unsigned char pad[0x24]; void* f24; };

extern "C" void func_ov003_02160134(void*);

// USA: func_ov017_021b6b5c
ARM void CallIfField24_021b6b5c(S021b6b5c* obj) {
	void* p = obj->f24;
	if (p) func_ov003_02160134(p);
}
