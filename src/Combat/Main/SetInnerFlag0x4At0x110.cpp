#include <globaldefs.h>
#pragma optimize_for_size off

struct Inner020bec10 {
    unsigned int pad[68];
    unsigned int flags;
};

struct Owner020bec10 {
    struct Inner020bec10* inner;
};

static inline bool HasInner(const struct Owner020bec10* o) { return o->inner != NULL; }

// USA: func_020bec10
ARM void SetInnerFlag0x4At0x110(struct Owner020bec10* owner) {
    if (HasInner(owner)) {
        owner->inner->flags |= 4;
    }
}
