#if defined(jpn)
#define R(j,u) (j)
#define data_ov024_021fe80c data_ov023_021fdad4
#define data_ov024_021fec60 data_ov023_021fdf18
#define data_ov024_021fed64 data_ov023_021fe018
#define func_ov023_021f8cf4 func_ov023_021f8180
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021fb2b0(void* obj, void* ctx, int arg2, int arg3, int arg5, int arg6);

struct EventNode02185dd4 {
    void* vtable;
    char pad[0x2c - 4];
};
extern char data_ov024_021fed64;

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac*, struct ListNode_021f67ac*);

// USA: func_ov011_02185dd4  (semantic: AllocateAndRegisterListEntry_02185dd4)
extern "C" ARM int func_ov011_02185dd4(struct TaggedNumber02184c30* tagged) {
    int v0 = GetTaggedValueAsInt_02184c30(tagged);
    int v1 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 8));
    int v2 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x10));
    int v3 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 0x18));

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, v1);
    if (!node) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* block = ((SafeAllocator*)((char*)node + 4))->Allocate(0x2c);
    if (!block) return 0;

    EventNode02185dd4 tmp;
    tmp.vtable = &data_ov024_021fed64;
    memcpy(block, &tmp, 0x2c);

    if (!func_ov023_021fb2b0(block, ctx, v0, v1, v2, v3)) return 0;

    void* obj = func_ov011_021849c8(ctx);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)obj, (struct ListNode_021f67ac*)block);
    return 1;
}
