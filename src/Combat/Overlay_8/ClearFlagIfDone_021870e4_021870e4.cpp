#include <globaldefs.h>

struct BitFlags02037180 {
    unsigned char pad0[0x40];
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
};
extern "C" int _ZNK8Object3D22HasAnimationReachedEndEv(struct BitFlags02037180* obj);
extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* a, void* b, int c);
extern int data_ov008_0218b495;

struct Obj021870e4 { char pad[0xb18]; unsigned int flags_b18; };

// USA: func_ov008_021870e4
ARM void ClearFlagIfDone_021870e4_021870e4(struct Obj021870e4* obj, unsigned int ticks) {
    if (!(obj->flags_b18 & 0x4000)) return;
    if (!_ZNK8Object3D22HasAnimationReachedEndEv((struct BitFlags02037180*)((char*)obj + 0x790))) return;
    _ZN8Object3D24MaybeSetRegularAnimationEPKci((char*)obj + 0x790, &data_ov008_0218b495, 0);
    obj->flags_b18 &= ~0x4000;
}
