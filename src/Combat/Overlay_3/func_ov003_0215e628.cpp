#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};

struct Obj0215e4c8 {
    unsigned char kind;
    signed char width;
    signed char height;
    signed char count;
    short* values;
};
void ClearStruct_0215e4c8(struct Obj0215e4c8* obj);

struct Self0215e898;
extern "C" void func_ov003_0215e898(struct Self0215e898* o, struct Obj0215e4c8* e);

struct Globals02180cb8 {
    void* allocator;
    struct Self0215e898* target;
};
extern struct Globals02180cb8 data_ov003_02180cb8;

// USA: func_ov003_0215e628
extern "C" ARM int func_ov003_0215e628(struct Variant02030b0c* params) {
    struct Obj0215e4c8 local;
    ClearStruct_0215e4c8(&local);
    local.kind = ((Script::Parameter*)&params[0])->ToInt();
    local.width = ((Script::Parameter*)&params[1])->ToInt();
    struct Variant02030b0c* heightParam = &params[2];
    params += 3;
    local.height = ((Script::Parameter*)heightParam)->ToInt();
    local.count = local.width * local.height;
    signed char count = local.count;
    short* dst = (short*)((SafeAllocator*)data_ov003_02180cb8.allocator)->Allocate(count * 2);
    local.values = dst;
    if (dst != NULL) {
        for (int i = 0; i < count; i++) {
            *dst = ((Script::Parameter*)(params++))->ToInt();
            dst++;
        }
    }
    func_ov003_0215e898(data_ov003_02180cb8.target, &local);
    return 1;
}
