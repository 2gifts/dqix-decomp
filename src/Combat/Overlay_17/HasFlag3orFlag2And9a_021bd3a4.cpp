#include <globaldefs.h>

struct Obj_021bd3a4 { unsigned char pad0[2]; unsigned char f2; unsigned char f3; unsigned char pad1[
#if defined(jpn)
0x92
#else
0x96
#endif
]; unsigned char f9a; };

// USA: func_ov017_021bd3a4
ARM int HasFlag3orFlag2And9a_021bd3a4(Obj_021bd3a4* obj) {
	if (obj->f3 == 0) {
		if (obj->f2 == 0 || obj->f9a == 0) {
			goto ret0;
		}
	}
	return 1;
ret0:
	return 0;
}
