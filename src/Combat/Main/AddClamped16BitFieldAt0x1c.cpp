#include <globaldefs.h>

struct S_a0530 {
    char pad[0x1c];
    unsigned int val : 16;
    unsigned int hi : 16;
};

// USA: func_020a0530
ARM void AddClamped16BitFieldAt0x1c_020a0530(struct S_a0530* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
