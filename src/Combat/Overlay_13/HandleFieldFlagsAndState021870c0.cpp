#include <globaldefs.h>

#if defined(jpn)
enum { flagOffset = 0x55 };
#define func_ov013_021878b0 func_ov013_021888c0
#else
enum { flagOffset = 0x69 };
#endif

extern "C" void func_ov013_021878b0(void* obj);
extern "C" void func_ov013_02187784(void* obj);

// USA: func_ov013_021870c0
// JPN: func_ov013_021882fc
ARM void HandleFieldFlagsAndState021870c0(void* obj) {
	unsigned char* o = (unsigned char*)obj;
	if (o[flagOffset] & 1) {
		func_ov013_021878b0(obj);
	}
#if !defined(jpn)
	if (o[0x64] == 1) {
		func_ov013_02187784(obj);
	}
#endif
}
