#include <globaldefs.h>

struct S021a99b0 { unsigned char pad[0x20]; void* f20; };

extern "C" void func_ov008_0218946c(char*);

// USA: func_ov017_021a99b0
ARM void CallIfField20_021a99b0(S021a99b0* obj) {
	void* p = obj->f20;
	if (p) func_ov008_0218946c((char*)p);
}
