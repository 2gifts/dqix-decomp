#include <globaldefs.h>
#include "System/OverlayId.h"

struct Obj021c0820;
struct S021b2ba0;
struct S021b2bdc;
struct HeadList020469f8;
struct HeadNode020469f8;

extern "C" void* func_ov017_0218b5b0();
extern "C" void _Z36InitAllocatorAndClearFields_021c0820P11Obj021c0820(Obj021c0820* obj);
extern "C" void _Z21InitObjState_021b2174Ph(unsigned char* obj);
extern "C" void _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(S021b2ba0* obj, char* name);
extern "C" void _Z25SetFields30And34_021b2bd0Pvii(void* obj, int handler, int overlayId);
extern "C" void _Z16SetBit3_021b2bdcP9S021b2bdcj(S021b2bdc* obj, unsigned int value);
void PrependNodeToHead(HeadList020469f8* list, HeadNode020469f8* node);

// JPN: func_ov017_021c0b28
// USA: func_ov017_021c0580
extern "C" ARM void func_ov017_021c0580(Obj021c0820* self, int kind, char* name, int handler) {
#if defined(jpn)
 enum {regionalOffset0=0x392c, regionalOffset1=0x34ec};
#else
 enum {regionalOffset0=0x3b4c, regionalOffset1=0x36fc};
#endif
    void* res = func_ov017_0218b5b0();
    HeadList020469f8* list;
    unsigned char* obj = *(unsigned char**)((char*)res + regionalOffset0);
    list = *(HeadList020469f8**)((char*)res + regionalOffset1);
    _Z36InitAllocatorAndClearFields_021c0820P11Obj021c0820(self);
    *(unsigned char*)((char*)self + 0x24) = kind;
    _Z21InitObjState_021b2174Ph(obj);
    _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc((S021b2ba0*)obj, name);
    _Z25SetFields30And34_021b2bd0Pvii(obj, handler, OVERLAY_ID(4));
    _Z16SetBit3_021b2bdcP9S021b2bdcj((S021b2bdc*)obj, 0);
    PrependNodeToHead(list, (HeadNode020469f8*)obj);
}
