#if defined(jpn)
#define R(j,u) (j)
#define data_ov024_021ff8c8 data_ov023_021feb44
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

struct TaggedInput02188184 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    TaggedNumber02184c30 c;
    TaggedNumber02184c30 d;
    TaggedNumber02184c30 e;
    TaggedNumber02184c30 f;
    TaggedNumber02184c30 g;
};

int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);

struct Obj_021fd320;
extern "C" ARM int func_ov023_021fd320(struct Obj_021fd320* obj, int unused, int val, int byteVal, int p5, int p6, int p7, int p8, int p9);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern int data_ov024_021ff8c8;

struct Buf02188184 { void* vtable; char pad[0x30 - 4]; };

// USA: func_ov011_02188184
extern "C" ARM int func_ov011_02188184(struct TaggedInput02188184* obj) {
    int tag0 = GetTaggedValueAsInt_02184c30(&obj->a);
    int tag8 = GetTaggedValueAsInt_02184c30(&obj->b);
    int tag10 = GetTaggedValueAsInt_02184c30(&obj->c);
    int tag18 = GetTaggedValueAsInt_02184c30(&obj->d);
    int tag20 = GetTaggedValueAsInt_02184c30(&obj->e);
    int tag28 = GetTaggedValueAsInt_02184c30(&obj->f);
    int tag30 = GetTaggedValueAsInt_02184c30(&obj->g);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x30);
    if (block == 0) return 0;

    struct Buf02188184 local;
    local.vtable = &data_ov024_021ff8c8;
    memcpy(block, &local, sizeof(Buf02188184));

    if (func_ov023_021fd320((struct Obj_021fd320*)block, (int)ctx, tag0, tag8, tag10, tag18, tag20, tag28, tag30) == 0) return 0;

    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(ctx), (struct ListNode_021f67ac*)block);
    return 1;
}
