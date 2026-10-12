#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021e3134 func_ov023_021e348c
#define func_ov023_021e4358 func_ov023_021e457c
#define func_ov023_021e43f0 func_ov023_021e4614
#endif

extern "C" void func_ov023_021e3fc0(void* obj);
extern "C" void func_ov023_021e4264(void* obj);
extern "C" void func_ov023_021e4358(void* obj);
extern "C" void func_ov023_021e43f0(void* obj);
extern "C" void func_ov005_02154ef0(int val);

// USA: func_ov023_021e3134  (semantic: RunChainIfFlagSet_021e3134)
extern "C" ARM void func_ov023_021e3134(void* obj) {
	#if defined(jpn)
	signed char v = *(signed char*)((char*)obj + 0x4e2);
#else
	signed char v = *(signed char*)((char*)obj + 0x4e6);
#endif
	if (v == 0) return;
	if (v == -1) return;
	func_ov023_021e3fc0(obj);
	func_ov023_021e4264(obj);
	func_ov023_021e4358(obj);
	func_ov023_021e43f0(obj);
	int val = *(int*)obj;
	if (val == 0) return;
	func_ov005_02154ef0(val);
}
