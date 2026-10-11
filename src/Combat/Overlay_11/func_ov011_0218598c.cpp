#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

struct TaggedNumber02184c4c;
extern float GetTaggedValueAsFloat_02184c4c(struct TaggedNumber02184c4c* v);

extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" int func_ov023_021f89f4(void* obj, void* ctx, int p2, int p3, int p4, int p5, int p6, int p7, int p8, int p9, int p10);

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov023_021fe708;

struct Event0218598c { void* vtable; char pad[0x50 - 4]; };

// USA: func_ov011_0218598c  (semantic: AllocateAndQueueEvent50_0218598c)
extern "C" ARM int func_ov011_0218598c(char* obj) {
    int v0 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)obj);
    int v1 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)(obj + 8));
    int v2 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)(obj + 0x10));
    int v3 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)(obj + 0x18));
    int v4 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)(obj + 0x20));
    int v5 = (int)GetTaggedValueAsFloat_02184c4c((struct TaggedNumber02184c4c*)(obj + 0x28));
    int v6 = (int)GetTaggedValueAsFloat_02184c4c((struct TaggedNumber02184c4c*)(obj + 0x30));
    int v7 = (int)GetTaggedValueAsFloat_02184c4c((struct TaggedNumber02184c4c*)(obj + 0x38));
    int v8 = (int)GetTaggedValueAsFloat_02184c4c((struct TaggedNumber02184c4c*)(obj + 0x40));

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, v1);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* slot = ((SafeAllocator*)((char*)node + 4))->Allocate(0x50);
    if (slot == 0) return 0;

    struct Event0218598c local;
    local.vtable = &data_ov023_021fe708;
    memcpy(slot, &local, sizeof(Event0218598c));

    if (func_ov023_021f89f4(slot, ctx, v0, v1, v2, v3, v4, v5, v6, v7, v8) == 0) return 0;

    void* list = func_ov011_021849c8(ctx);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)list, (struct ListNode_021f67ac*)slot);
    return 1;
}
