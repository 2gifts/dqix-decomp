#include <globaldefs.h>

struct S_a00d4 {
    char pad[0x10];
    unsigned int val : 16;
    unsigned int hi : 16;
};

// USA: func_020a00d4
ARM void AddClamped16BitFieldAt0x10_020a00d4(struct S_a00d4* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
