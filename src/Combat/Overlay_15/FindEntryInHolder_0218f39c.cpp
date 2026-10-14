#include <globaldefs.h>
#include "World/Object3D.h"

struct Holder02037558;

struct Obj0218f39c {
	char pad1c[0x1c];
	unsigned char state;
	char pad24[0x24 - 0x1d];
	struct Holder02037558* holder;
};

// USA: func_ov015_0218f39c  (semantic: FindEntryInHolder_0218f39c)
extern "C" ARM void* func_ov015_0218f39c(struct Obj0218f39c* obj, const char* name) {
	unsigned char state = obj->state;
	switch (state) {
	case 0:
	case 1:
		return ((Object3D*)obj->holder)->GetLoadedAnimationRecord(name);
	default:
		return ((Object3D*)obj->holder)->GetLoadedAnimationRecord(name);
	}
}
