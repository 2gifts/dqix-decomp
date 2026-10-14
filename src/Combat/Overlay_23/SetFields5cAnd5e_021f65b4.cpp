#include <globaldefs.h>

struct Obj5c_021f65b4 { char pad[0x5c]; unsigned short f5c; unsigned short f5e; };

extern "C" struct Obj5c_021f65b4* func_ov023_021f6524(void* a, void* b);

// USA: func_ov023_021f65b4
ARM void SetFields5cAnd5e_021f65b4(void* a, void* b, short v1, short v2) {
	struct Obj5c_021f65b4* p = func_ov023_021f6524(a, b);
	if (p != 0) {
		p->f5c = v1;
		p->f5e = v2;
	}
}
