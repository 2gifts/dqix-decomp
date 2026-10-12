#include <globaldefs.h>
#include "System/OverlayId.h"

#if defined(jpn)
#define data_020f233d data_020f2499
#define _Z32AllocateAndCopyStruct60_021633acP13SafeAllocatorPv func_ov004_021639a0
#endif

struct Obj0205eaa0;
struct S021b2ba0;
struct List02046a3c;
struct Node02046a3c;
struct SafeAllocator;

extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* obj, int a, int b);
extern "C" void* func_ov017_0218b5b0();
extern "C" void _Z21InitObjState_021b2174Ph(unsigned char* obj);
extern "C" void _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(S021b2ba0* obj, char* name);
extern "C" void _Z25SetFields30And34_021b2bd0Pvii(void* obj, int handler, int overlayId);
void InsertNodeAfterHead(List02046a3c* list, Node02046a3c* node);
extern "C" void _Z32AllocateAndCopyStruct60_021633acP13SafeAllocatorPv(SafeAllocator* allocator, void* arg);
extern char data_02108760;
extern char data_020f233d;

#if defined(jpn)
#define func_020d79e0 func_020d93e8
enum { kObjectOffset = 0x392c, kListOffset = 0x34ec };
#else
enum { kObjectOffset = 0x3b4c, kListOffset = 0x36fc };
#endif

// USA: func_020d79e0
extern "C" ARM void func_020d79e0(void* unused, int value) {
    void* res = func_ov017_0218b5b0();
    List02046a3c* list;
    unsigned char* obj = *(unsigned char**)((char*)res + kObjectOffset);
    list = *(List02046a3c**)((char*)res + kListOffset);
    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 1, 0);
    _Z21InitObjState_021b2174Ph(obj);
    *(int*)(obj + 0x4c) = value;
    _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc((S021b2ba0*)obj, &data_020f233d);
    _Z25SetFields30And34_021b2bd0Pvii(obj, (int)_Z32AllocateAndCopyStruct60_021633acP13SafeAllocatorPv, OVERLAY_ID(4));
    InsertNodeAfterHead(list, (Node02046a3c*)obj);
}
