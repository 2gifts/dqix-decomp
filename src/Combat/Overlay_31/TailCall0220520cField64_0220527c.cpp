#include <globaldefs.h>

struct Obj0220520c;
extern "C" int func_ov031_0220520c(void*, Obj0220520c*);

struct Obj0220527c {
	char pad[0x64];
	int field64;
};

// USA: func_ov031_0220527c
ARM int TailCall0220520cField64_0220527c(Obj0220527c* obj, void* extra) {
	return func_ov031_0220520c((void*)obj->field64, (Obj0220520c*)extra);
}
