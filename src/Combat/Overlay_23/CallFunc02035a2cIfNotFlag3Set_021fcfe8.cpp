#include <globaldefs.h>
#include "World/Object3D.h"

struct Obj20_021fcfe8 { char pad[0xc]; unsigned char flags; };

// USA: func_ov023_021fcfe8
ARM void CallFunc02035a2cIfNotFlag3Set_021fcfe8(struct Obj20_021fcfe8* obj) {
	if (obj->flags & 8) return;
	((Object3D*)((char*)obj + 0x20))->Draw(1);
}
