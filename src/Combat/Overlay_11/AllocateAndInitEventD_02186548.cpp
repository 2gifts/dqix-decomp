#if defined(jpn)
#define R(j,u) (j)
#define data_ov023_021ff7c4 data_ov023_021fea44
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct TaggedNumber02184c30;
int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

struct Obj0RowEvent;
struct Pair021fd1e0 { int a, b; };
struct BytePair021fd1e0 { unsigned char a, b; };
int InitEventD_021fd1e0(struct Obj0RowEvent* obj, int unused, int p2, int p3, struct Pair021fd1e0* p4, struct BytePair021fd1e0* p5);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void* ctx);

extern int data_ov023_021ff7c4;

struct Template02186548 {
    void* vtable;
    char pad[0x2c - 4];
};

// USA: func_ov011_02186548  (semantic: AllocateAndInitEventD_02186548)
extern "C" ARM int func_ov011_02186548(char* obj) {
    int a = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)obj);
    int b = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)(obj + 8));

    struct Pair021fd1e0 pair;
    pair.a = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)(obj + 0x10));
    pair.b = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)(obj + 0x18));

    struct BytePair021fd1e0 flags;
    flags.a = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)(obj + 0x20)) != 0;
    flags.b = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)(obj + 0x28)) != 0;

    void* ctx = func_ov017_021b2164();
    void* base = func_ov011_021845f8(ctx, b);
    if (base == 0) return 0;

    ((SafeAllocator*)((char*)base + 4))->GetSizeWithLargestBlockRemoved();
    void* newObj = ((SafeAllocator*)((char*)base + 4))->Allocate(0x2c);
    if (newObj == 0) return 0;

    struct Template02186548 local;
    local.vtable = &data_ov023_021ff7c4;
    memcpy(newObj, &local, 0x2c);

    if (InitEventD_021fd1e0((struct Obj0RowEvent*)newObj, (int)ctx, a, b, &pair, &flags) == 0) return 0;

    void* list = func_ov011_021849c8(ctx);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)newObj);
    return 1;
}
