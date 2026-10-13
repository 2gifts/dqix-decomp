#include <globaldefs.h>

struct Inner020bc158 { char pad[0x41]; unsigned char f41; };
struct Outer020bc158 { struct Inner020bc158 *f0; };

static inline bool HasInner(const struct Outer020bc158 *o) { return o->f0 != NULL; }

// USA: func_020bc158
ARM void SetInnerByte0x41(struct Outer020bc158 *p, unsigned char val) {
    if (HasInner(p)) {
        p->f0->f41 = val;
    }
}
