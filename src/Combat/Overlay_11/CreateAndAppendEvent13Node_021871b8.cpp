#if defined(jpn)
#define R(j,u) (j)
#define data_ov023_021ff4b0 data_ov023_021fe73c
#define func_ov023_021fc408 func_ov023_021fb700
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(void* node, unsigned int id);
extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021fc408(void* obj, void* unused, int b, int c, int p5, int p6, int p7, int p8, int p9, int p10);

struct EventNode021871b8 {
    void* vtable;
    char pad[0x30 - 4];
};
extern char data_ov023_021ff4b0;

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac*, struct ListNode_021f67ac*);

// USA: func_ov011_021871b8  (semantic: CreateAndAppendEvent13Node_021871b8)
extern "C" ARM int func_ov011_021871b8(struct TaggedNumber02184c30* tagged) {
    int v0 = GetTaggedValueAsInt_02184c30(tagged);
    int v1 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 8));
    int v2 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x10));
    int v3 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x18));
    int v4 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x20));
    int v5 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x28));
    int v6 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x30));
    int v7 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x38));

    void* base = func_ov017_021b2164();
    void* node = func_ov011_021845f8(base, v1);
    if (!node) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* slot = ((SafeAllocator*)((char*)node + 4))->Allocate(0x30);
    if (!slot) return 0;

    EventNode021871b8 tmp;
    tmp.vtable = &data_ov023_021ff4b0;
    memcpy(slot, &tmp, 0x30);

    if (!func_ov023_021fc408(slot, base, v0, v1, v2, v3, v4, v5, v6, v7)) return 0;

    void* obj = func_ov011_021849c8(base);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)obj, (struct ListNode_021f67ac*)slot);
    return 1;
}
