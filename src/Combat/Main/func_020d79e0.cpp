#include <globaldefs.h>
#include "System/OverlayId.h"
#include "Resource/GameResources.h"

struct Obj0205eaa0;
struct S021b2ba0;
struct List02046a3c;
struct Node02046a3c;
struct SafeAllocator;

struct StatusMenuRequest {
    unsigned char unknown0[0x4c];
    int selectedMember;
};

extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* obj, int a, int b);
extern "C" void _Z21InitObjState_021b2174Ph(unsigned char* obj);
extern "C" void _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(S021b2ba0* obj, char* name);
extern "C" void _Z25SetFields30And34_021b2bd0Pvii(void* obj, int handler, int overlayId);
void InsertNodeAfterHead(List02046a3c* list, Node02046a3c* node);
extern "C" void _Z32AllocateAndCopyStruct60_021633acP13SafeAllocatorPv(SafeAllocator* allocator, void* arg);
extern char data_02108760;
extern char data_020f233d;

// USA: func_020d79e0
extern "C" ARM void func_020d79e0(void* unused, int selectedMember) {
    GameResources* res = func_ov017_0218b5b0();
    List02046a3c* list;
    StatusMenuRequest* request = static_cast<StatusMenuRequest*>(res->unknown_ptr_array_3afc[20]);
    list = static_cast<List02046a3c*>(res->unknown_ptr_array_36fc[0]);
    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 1, 0);
    _Z21InitObjState_021b2174Ph(reinterpret_cast<unsigned char*>(request));
    request->selectedMember = selectedMember;
    _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc((S021b2ba0*)request, &data_020f233d);
    _Z25SetFields30And34_021b2bd0Pvii(request, (int)_Z32AllocateAndCopyStruct60_021633acP13SafeAllocatorPv, OVERLAY_ID(4));
    InsertNodeAfterHead(list, (Node02046a3c*)request);
}
