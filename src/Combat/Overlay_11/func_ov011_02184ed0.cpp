#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

extern "C" int _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* _Z13NoOp_021845f4v(void);
extern "C" ARM void* func_ov011_021842c8(unsigned char* node, unsigned int id);
extern "C" ARM void func_ov011_021842a0(void* obj);

struct Chain02184354;
extern "C" int _Z24SetFieldOrChain_02184354P13Chain02184354i(Chain02184354* obj, int val);

struct MenuHeap02184ed0 {
    int id;
    SafeAllocator allocator;
};

// USA: func_ov011_02184ed0
extern "C" ARM int func_ov011_02184ed0(struct TaggedNumber02184c30* params, int count, MenuHeap02184ed0* heap) {
    unsigned int parentId;
    int id;
    unsigned char* heaps;
    MenuHeap02184ed0* parent;
    void* buffer;

    parentId = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[0]);
    id = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[1]);
    func_ov017_021b2164();
    heaps = (unsigned char*)_Z13NoOp_021845f4v();
    parent = (MenuHeap02184ed0*)func_ov011_021842c8(heaps, parentId);
    if (parent == 0)
        return 0;
    if (func_ov011_021842c8(heaps, id) != 0)
        return 0;

    heap = (MenuHeap02184ed0*)parent->allocator.Allocate(0x20);
    if (heap == 0)
        return 0;

    func_ov011_021842a0(heap);
    heap->id = id;
    if (count >= 3)
        parentId = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[2]);
    else
        parentId = parent->allocator.GetMaxPossibleAllocation();
    if (parentId == 0)
        return 0;

    buffer = parent->allocator.Allocate(parentId);
    if (buffer == 0)
        return 0;

    heap->allocator.CreateTypeB(buffer, parentId, 4);
    _Z24SetFieldOrChain_02184354P13Chain02184354i((Chain02184354*)parent, (int)heap);
    return 1;
}
