#include <globaldefs.h>

#if defined(jpn)
enum { kByteOffset = 0x4e };
#else
enum { kByteOffset = 0x4a };
#endif


#if defined(jpn)
#define func_ov023_021fb2a8 func_ov023_021fa650
#endif

struct S021fb2a8 { char pad[kByteOffset]; unsigned char field4a; };

// USA: func_ov023_021fb2a8  (semantic: SetField4a_021fb2a8)
extern "C" ARM void func_ov023_021fb2a8(struct S021fb2a8 *obj, unsigned char v) {
	obj->field4a = v;
}
