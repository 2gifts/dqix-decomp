#include <globaldefs.h>

extern "C" void func_ov000_0217f518(void*);
extern "C" void func_ov000_0217636c(void*, int);

struct Struct02170fd0 {
	unsigned char pad0[0x38];
	int f38;
};

// USA: func_ov000_02170fd0
ARM void CallHandlerIfF38Set02170fd0(struct Struct02170fd0* obj, int b) {
	func_ov000_0217f518(obj);
	if (obj->f38 != 0) {
		func_ov000_0217636c(obj, b);
	}
}
