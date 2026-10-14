#include <globaldefs.h>

struct S_a03c4 {
    char pad[0x10];
    unsigned int val : 9;
    unsigned int hi : 23;
};

// USA: func_020a03c4
ARM void AddClamped9BitFieldAt0x10_020a03c4(struct S_a03c4* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x1f4) {
        v = 0x1f4;
    }
    p->val = v;
}
