#include <globaldefs.h>
#include "System/OverlayId.h"

struct S021b2ba0;
struct S021b2bdc;
struct S021b2bf4;
struct S021b2c0c;
struct TailList020469b4;
struct TailNode020469b4;
struct SafeAllocator;

extern "C" void* func_ov017_0218b5b0();
extern "C" void _Z21InitObjState_021b2174Ph(unsigned char* obj);
extern "C" void _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(S021b2ba0* obj, char* name);
extern "C" void _Z25SetFields30And34_021b2bd0Pvii(void* obj, int handler, int overlayId);
extern "C" void _Z16SetBit4_021b2bf4P9S021b2bf4j(S021b2bf4* obj, unsigned int value);
extern "C" void _Z16SetBit5_021b2c0cP9S021b2c0cj(S021b2c0c* obj, unsigned int value);
extern "C" void _Z16SetBit3_021b2bdcP9S021b2bdcj(S021b2bdc* obj, unsigned int value);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
extern "C" void _Z29AllocateAndCopyBuf20_021689d8P13SafeAllocatorPv(SafeAllocator* allocator, void* arg);
extern char data_ov017_021d75d0;

// JPN: func_ov017_0219d010
// USA: func_ov017_0219c520
extern "C" ARM void func_ov017_0219c520() {
#if defined(jpn)
 enum {regionalOffset0=0x392c, regionalOffset1=0x34ec};
#else
 enum {regionalOffset0=0x3b4c, regionalOffset1=0x36fc};
#endif
    void* res = func_ov017_0218b5b0();
    TailList020469b4* list;
    unsigned char* obj = *(unsigned char**)((char*)res + regionalOffset0);
    list = *(TailList020469b4**)((char*)res + regionalOffset1);
    _Z21InitObjState_021b2174Ph(obj);
    _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc((S021b2ba0*)obj, &data_ov017_021d75d0);
    _Z25SetFields30And34_021b2bd0Pvii(obj, (int)_Z29AllocateAndCopyBuf20_021689d8P13SafeAllocatorPv, OVERLAY_ID(4));
    _Z16SetBit4_021b2bf4P9S021b2bf4j((S021b2bf4*)obj, 1);
    _Z16SetBit5_021b2c0cP9S021b2c0cj((S021b2c0c*)obj, 1);
    _Z16SetBit3_021b2bdcP9S021b2bdcj((S021b2bdc*)obj, 0);
    AppendNodeToTail(list, (TailNode020469b4*)obj);
}
