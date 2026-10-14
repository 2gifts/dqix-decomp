#include <globaldefs.h>
#include "World/Object3D.h"

struct Obj0218f364 {
	char pad1c[0x1c];
	unsigned char state;
	char pad24[0x24 - 0x1d];
	void* holder;
	char pad44[0x44 - 0x28];
	int flags;
};

// USA: func_ov015_0218f364  (semantic: DispatchHolderWithFlag8_0218f364)
extern "C" ARM void func_ov015_0218f364(struct Obj0218f364* obj, void* p) {
	unsigned char state = obj->state;
	switch (state) {
	case 0:
	case 1:
		((Object3D*)obj->holder)->MaybeSetRegularAnimation((char const*)p, obj->flags | 8);
		return;
	default:
		((Object3D*)obj->holder)->MaybeSetRegularAnimation((char const*)p, obj->flags | 8);
		return;
	}
}
