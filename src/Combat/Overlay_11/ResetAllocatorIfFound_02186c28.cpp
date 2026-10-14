#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct TaggedNumber02184c30;
int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void func_ov023_021f6844(void* extra, int v);

// USA: func_ov011_02186c28
ARM int ResetAllocatorIfFound_02186c28(struct TaggedNumber02184c30* p) {
    int v = GetTaggedValueAsInt_02184c30(p);
    void* ctx = func_ov017_021b2164();
    void* obj = func_ov011_021845f8(ctx, v);
    if (obj == 0) return 0;
    func_ov023_021f6844(func_ov011_021849c8(ctx), v);
    ((SafeAllocator*)((char*)obj + 4))->Reset();
    return 1;
}
