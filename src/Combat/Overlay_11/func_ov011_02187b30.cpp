#if defined(jpn)
#define R(j,u) (j)
#define data_ov024_021ff6b8 data_ov023_021fe93c
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
int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

struct TaggedInput02187b30 {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    TaggedNumber02184c30 c;
    int sel;
    int val;
};

extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);

struct Obj0RowEvent;
int InitEvent14_021fcdd4(struct Obj0RowEvent* obj, int p1, int p2, int p3, int p4, int p5);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov024_021ff6b8;

struct Template02187b30 { void* vtable; char pad[0xcc - 4]; };

// USA: func_ov011_02187b30  (semantic: AllocateAndInitEvent14_02187b30)
extern "C" ARM int func_ov011_02187b30(struct TaggedInput02187b30* obj) {
    int tag0 = GetTaggedValueAsInt_02184c30(&obj->a);
    int tag8 = GetTaggedValueAsInt_02184c30(&obj->b);
    int tag10 = GetTaggedValueAsInt_02184c30(&obj->c);
    int sb;
    if (obj->sel == 2) sb = obj->val;
    else sb = 0;
    if (sb == 0) return 0;

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0xcc);
    if (block == 0) return 0;

    struct Template02187b30 local;
    local.vtable = &data_ov024_021ff6b8;
    memcpy(block, &local, sizeof(local));

    if (InitEvent14_021fcdd4((struct Obj0RowEvent*)block, (int)ctx, tag0, tag8, tag10, sb) == 0) return 0;

    void* list = func_ov011_021849c8(ctx);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)block);
    return 1;
}
