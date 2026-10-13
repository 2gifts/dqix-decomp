#include <globaldefs.h>
#include "System/OverlayId.h"
#include "Resource/GameResources.h"

struct Obj0205eaa0;
struct S021b2ba0;
struct TailList020469b4;
struct TailNode020469b4;
struct SafeAllocator;

extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* obj, int a, int b);
extern "C" void _Z21InitObjState_021b2174Ph(unsigned char* obj);
extern "C" void _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(S021b2ba0* obj, char* name);
extern "C" void _Z25SetFields30And34_021b2bd0Pvii(void* obj, int handler, int overlayId);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
extern "C" void _Z35CopyGlobalBlockAndDispatch_02165df4P13SafeAllocatorPv(SafeAllocator* allocator, void* arg);
extern char data_02108760;
extern char data_020f2334;

// USA: func_020d7978
extern "C" ARM void func_020d7978() {
    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 1, 0);
    GameResources* res = func_ov017_0218b5b0();
    TailList020469b4* list;
    unsigned char* obj = static_cast<unsigned char*>(res->unknown_ptr_array_3afc[20]);
    list = static_cast<TailList020469b4*>(res->unknown_ptr_array_36fc[0]);
    _Z21InitObjState_021b2174Ph(obj);
    _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc((S021b2ba0*)obj, &data_020f2334);
    _Z25SetFields30And34_021b2bd0Pvii(obj, (int)_Z35CopyGlobalBlockAndDispatch_02165df4P13SafeAllocatorPv, OVERLAY_ID(4));
    AppendNodeToTail(list, (TailNode020469b4*)obj);
}
