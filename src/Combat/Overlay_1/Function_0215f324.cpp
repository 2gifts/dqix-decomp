#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_02012fe4(void* obj);
extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov001_0215f324
ARM int Function_0215f324(void* obj) {
	unsigned short v = *(unsigned short*)((char*)func_02012fe4(obj) + 2);
	func_ov017_021d6134(obj, v);
	return 1;
}
