#include <globaldefs.h>

struct Inner020bc16c { char pad[0x40]; unsigned char f40; };
struct Outer020bc16c { struct Inner020bc16c *f0; };

static inline bool HasInner(const struct Outer020bc16c *o) { return o->f0 != NULL; }

// USA: func_020bc16c
ARM void SetInnerByte0x40(struct Outer020bc16c *p, unsigned char val) {
    if (HasInner(p)) {
        p->f0->f40 = val;
    }
}
