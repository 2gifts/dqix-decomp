#include <globaldefs.h>

struct S_a0140 {
    char pad[0x14];
    unsigned int val : 10;
    unsigned int hi : 22;
};

// USA: func_020a0140
ARM void AddClamped10BitFieldAt0x14_020a0140(struct S_a0140* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x3ff) {
        v = 0x3ff;
    }
    p->val = v;
}
