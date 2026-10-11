#if defined(jpn)
#define R(j,u) (j)
#define data_ov023_021fef74 data_ov023_021fe220
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
extern "C" int _Z25SetFieldsAndInit_021fba80Pviss(void* a, int b, short c, short d);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
extern "C" void _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov023_021fef74;

struct MenuHeap021866e0 {
    int id;
    SafeAllocator allocator;
};

struct MenuObject021866e0 {
    void* vtable;
    char pad[0x24 - 4];
};

// USA: func_ov011_021866e0
extern "C" ARM int func_ov011_021866e0(struct TaggedNumber02184c30* params, int count) {
    int id = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[0]);
    int heapId = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[1]);
    void* script = func_ov017_021b2164();
    MenuHeap021866e0* heap = (MenuHeap021866e0*)func_ov011_021845f8(script, heapId);
    if (heap == 0)
        return 0;

    heap->allocator.GetSizeWithLargestBlockRemoved();
    void* object = heap->allocator.Allocate(sizeof(MenuObject021866e0));
    if (object == 0)
        return 0;

    MenuObject021866e0 prototype;
    prototype.vtable = &data_ov023_021fef74;
    memcpy(object, &prototype, sizeof(MenuObject021866e0));
    if (!((int (*)(void*, void*, int, int))_Z25SetFieldsAndInit_021fba80Pviss)(object, script, id, heapId))
        return 0;

    _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(script), (struct ListNode_021f67ac*)object);
    return 1;
}
