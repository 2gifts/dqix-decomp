#include <globaldefs.h>

struct S_a0038 {
    char pad[0x8];
    unsigned int lo : 16;
    unsigned int val : 16;
};

// USA: func_020a0038
ARM void AddClampedHigh16BitFieldAt0x8_020a0038(struct S_a0038* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
