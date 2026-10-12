#include <globaldefs.h>

struct Inner020bc1cc { char pad[0x3c]; unsigned char f3c; };
struct Outer020bc1cc { struct Inner020bc1cc* f0; };

void NotifyInnerByte0x3c(struct Outer020bc1cc*, int, int);
extern void* data_ov031_02290d00;

// USA: func_ov031_022368bc
extern "C" ARM void func_ov031_022368bc(int arg2, int arg3) {
	NotifyInnerByte0x3c((struct Outer020bc1cc*)((char*)data_ov031_02290d00 + 0x94), arg2, arg3);
}
