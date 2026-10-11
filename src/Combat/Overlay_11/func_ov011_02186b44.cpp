#if defined(jpn)
#define R(j,u) (j)
#define data_ov024_021ff280 data_ov023_021fe520
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

extern "C" int _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM int func_ov023_021fbe08(void* obj, void* script, int id, int heapId, int unk);
extern "C" void* _Z22ZeroInitReturn020de824Pv(void* obj);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
extern "C" void _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov024_021ff280;

struct MenuHeap02186b44 {
    int id;
    SafeAllocator allocator;
};

struct MenuObject02186b44 {
    void* vtable;
    char pad[0x20 - 4];
    SafeAllocator allocator;
    char part[0x50 - 0x34];
};

// USA: func_ov011_02186b44
extern "C" ARM int func_ov011_02186b44(struct TaggedNumber02184c30* params, int count) {
    int unk;
    int id = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[0]);
    int heapId = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[1]);
    unk = 0;
    if (count - 2 != 0)
        unk = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[2]);

    void* script = func_ov017_021b2164();
    MenuHeap02186b44* heap = (MenuHeap02186b44*)func_ov011_021845f8(script, heapId);
    if (heap == 0)
        return 0;

    heap->allocator.GetSizeWithLargestBlockRemoved();
    void* object = heap->allocator.Allocate(sizeof(MenuObject02186b44));
    if (object == 0)
        return 0;

    MenuObject02186b44 prototype;
    prototype.vtable = &data_ov024_021ff280;
    prototype.allocator.ResetAllocatorPointer();
    _Z22ZeroInitReturn020de824Pv(prototype.part);
    memcpy(object, &prototype, sizeof(MenuObject02186b44));
    if (!func_ov023_021fbe08(object, script, id, heapId, unk))
        return 0;

    _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(script), (struct ListNode_021f67ac*)object);
    return 1;
}
