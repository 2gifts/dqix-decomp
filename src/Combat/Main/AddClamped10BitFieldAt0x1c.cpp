#include <globaldefs.h>

struct S_a0258 {
    char pad[0x1c];
    unsigned int val : 10;
    unsigned int hi : 22;
};

// USA: func_020a0258
ARM void AddClamped10BitFieldAt0x1c_020a0258(struct S_a0258* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x3ff) {
        v = 0x3ff;
    }
    p->val = v;
}
