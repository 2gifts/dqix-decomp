#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv _Z27CheckAnyBuffBelow2_021f5c80P16Wrapper_021f5c80iiPiPs
#define _Z40InitTenAllocatorsAndClearFields_021e4e8cPv func_ov023_021e5080
#define data_ov023_021ff5b4 data_ov023_021fe83c
#define func_ov023_021fc518 func_ov023_021fb810
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
extern "C" ARM void* func_ov017_0218b5b0(void);
extern "C" ARM int func_ov023_021fc518(void* obj, void* script, int id, int heapId, int unk2, int unk);
extern "C" void _Z40InitTenAllocatorsAndClearFields_021e4e8cPv(void* model);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
extern "C" void _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov023_021ff5b4;

struct MenuHeap02187720 {
    int id;
    SafeAllocator allocator;
};

struct CharacterModel02187720 {
    char parts[0x6b8];
    SafeAllocator allocators[10];
    SafeAllocator animationAllocator;
    char rest[0xc20 - 0x794];
};

struct MenuObject02187720 {
    void* vtable;
    char unk_4[0x1c];
    CharacterModel02187720 models[2];
    char unk_1860[0x10];
};

// USA: func_ov011_02187720
extern "C" ARM int func_ov011_02187720(struct TaggedNumber02184c30* params, int count) {
    MenuObject02187720 prototype;
    void* object;
    SafeAllocator* allocator;
    CharacterModel02187720* model;
    int unk;
    MenuHeap02187720* heap;
    void* script;
    int heapId;
    int unk2;
    int id;

    id = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[0]);
    heapId = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[1]);
    unk2 = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[2]);
    _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[3]);
    script = func_ov017_021b2164();
    heap = (MenuHeap02187720*)func_ov011_021845f8(script, heapId);
    if (heap == 0)
        return 0;

    heap->allocator.GetSizeWithLargestBlockRemoved();
    unk = (*(int**)((char*)func_ov017_0218b5b0() + R(0x392c, 0x3b4c)))[0x13];
    object = heap->allocator.Allocate(sizeof(MenuObject02187720));
    if (object == 0)
        return 0;

    prototype.vtable = &data_ov023_021ff5b4;
    model = prototype.models;
    do {
        allocator = model->allocators;
        do {
            allocator->ResetAllocatorPointer();
            allocator++;
        } while (allocator < model->allocators + 10);
        model->animationAllocator.ResetAllocatorPointer();
        _Z40InitTenAllocatorsAndClearFields_021e4e8cPv(model);
        model++;
    } while (model < prototype.models + 2);
    memcpy(object, &prototype, sizeof(MenuObject02187720));
    if (!func_ov023_021fc518(object, script, id, heapId, unk2, unk))
        return 0;

    _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(script), (struct ListNode_021f67ac*)object);
    return 1;
}
