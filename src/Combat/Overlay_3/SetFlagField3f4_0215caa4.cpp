#include <globaldefs.h>

#if defined(jpn)
enum { flagOffset = 0x40c };
#else
enum { flagOffset = 0x3f4 };
#endif
struct ObjField3f4_0215caa4 { char pad[flagOffset]; unsigned char field3f4; };

// USA: func_ov003_0215caa4  (semantic: SetFlagField3f4_0215caa4)
extern "C" ARM void func_ov003_0215caa4(struct ObjField3f4_0215caa4* obj) {
	obj->field3f4 = 1;
}
