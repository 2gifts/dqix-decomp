#include <globaldefs.h>

struct S_a0068 {
    char pad[0xc];
    unsigned int val : 16;
    unsigned int hi : 16;
};

// USA: func_020a0068
ARM void AddClampedLow16BitFieldAt0xc_020a0068(struct S_a0068* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
