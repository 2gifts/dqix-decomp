#include <globaldefs.h>

struct S_a0364 {
    char pad[0x8];
    unsigned int lo : 24;
    unsigned int val : 8;
};

// USA: func_020a0364
ARM void AddClampedTopByteAt0x8_020a0364(struct S_a0364* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xfa) {
        v = 0xfa;
    }
    p->val = v;
}
