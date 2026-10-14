#include <globaldefs.h>
#include "World/Object3D.h"

struct Obj021fcfd0 {
	char pad0[0x1c];
	int result;
};

// USA: func_ov023_021fcfd0
ARM int RunAndGetResult_021fcfd0(struct Obj021fcfd0 *obj) {
	((Object3D*)((char*)obj + 0x20))->AdvanceEffects();
	return obj->result;
}
