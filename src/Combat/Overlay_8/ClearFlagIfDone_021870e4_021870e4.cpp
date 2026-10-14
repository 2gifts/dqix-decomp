#include <globaldefs.h>
#include "World/Object3D.h"

struct BitFlags02037180 {
    unsigned char pad0[0x40];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
};
extern int data_ov008_0218b495;

struct Obj021870e4 { char pad[0xb18]; unsigned int flags_b18; };

// USA: func_ov008_021870e4
ARM void ClearFlagIfDone_021870e4_021870e4(struct Obj021870e4* obj, unsigned int ticks) {
    if (!(obj->flags_b18 & 0x4000)) return;
    if (!((Object3D*)((struct BitFlags02037180*)((char*)obj + 0x790)))->HasAnimationReachedEnd()) return;
    ((Object3D*)((char*)obj + 0x790))->MaybeSetRegularAnimation((char const*)&data_ov008_0218b495, 0);
    obj->flags_b18 &= ~0x4000;
}
