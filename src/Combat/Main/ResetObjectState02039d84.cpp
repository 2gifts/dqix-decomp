#include <globaldefs.h>
#include "Combat/ActorAction.h"

struct Bytes02033b88;

extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);

struct Obj02039d84 {
    unsigned char pad[0xe0];
    unsigned char flags_e0;
};

// USA: func_02039d84
ARM void ResetObjectState02039d84(struct Obj02039d84* obj) {
    obj->flags_e0 &= ~1;
    _ZN8Object3D11DisableFlagEi((unsigned char*)obj, 0x1190);
#if defined(jpn)
    InitBlock02038508((struct SubBlock02038508*)((char*)obj + 0x260));
#else
    InitBlock02038508((struct SubBlock02038508*)((char*)obj + 0x26c));
#endif
    SetByte0xbeShiftPrev((struct Bytes02033b88*)obj, 0);
}
