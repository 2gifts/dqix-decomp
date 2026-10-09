#include <globaldefs.h>

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* thisPtr, unsigned int size);

struct Obj0215e4c8 {
    unsigned char kind;
    signed char width;
    signed char height;
    signed char count;
    short* values;
};
extern "C" void _Z20ClearStruct_0215e4c8P11Obj0215e4c8(struct Obj0215e4c8* obj);

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
    _Z20ClearStruct_0215e4c8P11Obj0215e4c8(&local);
    local.kind = _ZNK6Script9Parameter5ToIntEv(&params[0]);
    local.width = _ZNK6Script9Parameter5ToIntEv(&params[1]);
    struct Variant02030b0c* heightParam = &params[2];
    params += 3;
    local.height = _ZNK6Script9Parameter5ToIntEv(heightParam);
    local.count = local.width * local.height;
    signed char count = local.count;
    short* dst = (short*)_ZN13SafeAllocator8AllocateEj(data_ov003_02180cb8.allocator, count * 2);
    local.values = dst;
    if (dst != NULL) {
        for (int i = 0; i < count; i++) {
            *dst = _ZNK6Script9Parameter5ToIntEv(params++);
            dst++;
        }
    }
    func_ov003_0215e898(data_ov003_02180cb8.target, &local);
    return 1;
}
