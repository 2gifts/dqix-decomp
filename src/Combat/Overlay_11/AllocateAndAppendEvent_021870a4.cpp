#if defined(jpn)
#define R(j,u) (j)
#define data_ov024_021ff384 data_ov023_021fe620
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(void* ctx, unsigned int id);
extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021fc1f4(void* slot, void* ctx, int v0, int v1);

struct EventNode021870a4 {
    void* vtable;
    char pad[0x2c - 4];
};
extern char data_ov024_021ff384;

struct ListHead_021f67ac;
struct ListNode_021f67ac;
void AppendNodeToList_021f67ac(struct ListHead_021f67ac*, struct ListNode_021f67ac*);

// USA: func_ov011_021870a4  (semantic: AllocateAndAppendEvent_021870a4)
extern "C" ARM int func_ov011_021870a4(struct TaggedNumber02184c30* tagged) {
    int v0 = GetTaggedValueAsInt_02184c30(tagged);
    int v1 = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 8));

    void* ctx = func_ov017_021b2164();
    void* node = func_ov011_021845f8(ctx, v1);
    if (!node) return 0;

    ((SafeAllocator*)((char*)node + 4))->GetSizeWithLargestBlockRemoved();
    void* slot = ((SafeAllocator*)((char*)node + 4))->Allocate(0x2c);
    if (!slot) return 0;

    EventNode021870a4 tmp;
    tmp.vtable = &data_ov024_021ff384;
    memcpy(slot, &tmp, 0x2c);

    if (!func_ov023_021fc1f4(slot, ctx, v0, v1)) return 0;

    void* obj = func_ov011_021849c8(ctx);
    AppendNodeToList_021f67ac((struct ListHead_021f67ac*)obj, (struct ListNode_021f67ac*)slot);
    return 1;
}
