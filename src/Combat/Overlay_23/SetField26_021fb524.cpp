#include <globaldefs.h>

#if defined(jpn)
#define func_ov023_021fb524 func_ov023_021fa8cc
#endif

struct S021fb524 { char pad[0x26]; unsigned short field26; };

// USA: func_ov023_021fb524  (semantic: SetField26_021fb524)
extern "C" ARM void func_ov023_021fb524(struct S021fb524 *obj, unsigned short v) {
	obj->field26 = v;
}
