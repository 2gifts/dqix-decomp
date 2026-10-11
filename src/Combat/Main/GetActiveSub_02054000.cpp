#include <globaldefs.h>

struct Inner_02054000 {
    char pad0[0x294];
    char field294;
    char pad1[0x496 - 0x295];
    short field496;
};

struct Outer_02054000 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    struct Inner_02054000* inner;
};

// USA: func_02054000
ARM void* GetActiveSub_02054000(struct Outer_02054000* p) {
    struct Inner_02054000* inner = p->inner;
    if (inner != 0) {
        if (inner->field496 > 0) {
            return &inner->field294;
        }
    }
    return 0;
}
