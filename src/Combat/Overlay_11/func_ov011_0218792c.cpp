#if defined(jpn)
#define R(j,u) (j)
#define data_ov023_021fe4f0 data_ov023_021fd7c0
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

struct TaggedInput0218792c {
    TaggedNumber02184c30 a;
    TaggedNumber02184c30 b;
    TaggedNumber02184c30 c;
    TaggedNumber02184c30 d;
    TaggedNumber02184c30 e;
};

int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021845f8(void* ctx, int v);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
#if defined(jpn)
extern "C" ARM int func_ov023_021f745c(void* buf, void* obj, int arg2, int arg3, int p5, int p7, int p8, int p9);
#else
extern "C" ARM int func_ov023_021f745c(void* buf, void* obj, int arg2, int arg3, int p5, int p6, int p7, int p8, int p9);
#endif

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac* head, struct ListNode_021f67ac* node);

extern char data_ov023_021fe4f0;

struct Buf0218792c { void* magic; char pad[R(0x50, 0x54) - 4]; };

// USA: func_ov011_0218792c
extern "C" ARM int func_ov011_0218792c(struct TaggedInput0218792c* obj) {
    int tag0 = GetTaggedValueAsInt_02184c30(&obj->a);
    int tag8 = GetTaggedValueAsInt_02184c30(&obj->b);
    int tag16 = GetTaggedValueAsInt_02184c30(&obj->c);
    int tag24 = GetTaggedValueAsInt_02184c30(&obj->d);
    int tag32 = GetTaggedValueAsInt_02184c30(&obj->e);

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, tag8);
    if (node == 0) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(R(0x50, 0x54));
    if (block == 0) return 0;

    struct Buf0218792c local;
    local.magic = &data_ov023_021fe4f0;
    memcpy(block, &local, sizeof(Buf0218792c));

#if defined(jpn)
    if (func_ov023_021f745c(block, ctx, tag0, tag8, 0, tag16, tag24, tag32) == 0) return 0;
#else
    if (func_ov023_021f745c(block, ctx, tag0, tag8, 0, 0, tag16, tag24, tag32) == 0) return 0;
#endif

    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)func_ov011_021849c8(ctx), (struct ListNode_021f67ac*)block);
    return 1;
}
