#include <globaldefs.h>
#if defined(jpn)
enum { kRegion960 = 0x800 };
#else
enum { kRegion960 = 0x960 };
#endif
#include "std_library_functions.h"

struct StructA0205d5d0;
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(StructA0205d5d0*, int, int, int);
#endif
extern int TryApplyElemFields0205d5d0(StructA0205d5d0* a, int b, int c, int d, unsigned char e);
extern "C" void func_ov003_0215b964(void* obj, void* p, int flag);

// JPN: func_ov003_0215d148
// USA: func_ov003_0215be20
ARM void ResetAndApply0215be20(void* obj) {
	memset(*(void**)((char*)obj + 0x7c), 0, kRegion960);
	func_ov003_0215b964(obj, *(void**)((char*)obj + 0x7c), 0);
#if defined(jpn)
	_Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((StructA0205d5d0*)((char*)obj + 0xf4), 2, *(int*)((char*)obj + 0x7c), 1);
#else
	TryApplyElemFields0205d5d0((StructA0205d5d0*)((char*)obj + 0xf4), 2, *(int*)((char*)obj + 0x7c), 1, 0);
#endif
}
