#include <globaldefs.h>

struct Obj0220520c;
extern "C" int func_ov031_0220520c(void*, Obj0220520c*);

struct Obj0220528c {
	char pad[0x68];
	int field68;
};

// USA: func_ov031_0220528c
ARM int TailCall0220520cField68_0220528c(Obj0220528c* obj, void* extra) {
	return func_ov031_0220520c((void*)obj->field68, (Obj0220520c*)extra);
}
