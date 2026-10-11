#if defined(jpn)
#define R(j,u) (j)
#define data_ov023_021fe604 data_ov023_021fd8d0
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

struct TaggedInput02185318 {
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

struct Obj021f7da0;
extern "C" ARM int func_ov023_021f7da0(struct Obj021f7da0* obj, void* ctx, int arg3, int arg4, int arg5, int arg6, int arg7, int arg8, int arg9);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern int data_ov023_021fe604;

struct Buf02185318 { void* vtable; char pad[0x110 - 4]; };

// USA: func_ov011_02185318
extern "C" ARM int func_ov011_02185318(struct TaggedInput02185318* obj) {
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
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x110);
    if (block == 0) return 0;

    struct Buf02185318 local;
    local.vtable = &data_ov023_021fe604;
    memcpy(block, &local, sizeof(Buf02185318));

    if (func_ov023_021f7da0((struct Obj021f7da0*)block, ctx, tag0, tag8, tag10, tag18, tag20, tag28, tag30) == 0) return 0;

    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(ctx), (struct ListNode_021f67ac*)block);
    return 1;
}
