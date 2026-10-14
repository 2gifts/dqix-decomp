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
void InitObjState_021b2174(unsigned char* obj);
void SetNameChecked_021b2ba0(S021b2ba0* obj, char* name);
void SetFields30And34_021b2bd0(void* obj, int handler, int overlayId);
void SetBit4_021b2bf4(S021b2bf4* obj, unsigned int value);
void SetBit5_021b2c0c(S021b2c0c* obj, unsigned int value);
void SetBit3_021b2bdc(S021b2bdc* obj, unsigned int value);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void AllocateAndCopyBuf20_021689d8(SafeAllocator* allocator, void* arg);
extern char data_ov017_021d75d0;

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
    InitObjState_021b2174(obj);
    SetNameChecked_021b2ba0((S021b2ba0*)obj, &data_ov017_021d75d0);
    SetFields30And34_021b2bd0(obj, (int)AllocateAndCopyBuf20_021689d8, OVERLAY_ID(4));
    SetBit4_021b2bf4((S021b2bf4*)obj, 1);
    SetBit5_021b2c0c((S021b2c0c*)obj, 1);
    SetBit3_021b2bdc((S021b2bdc*)obj, 0);
    AppendNodeToTail(list, (TailNode020469b4*)obj);
}
