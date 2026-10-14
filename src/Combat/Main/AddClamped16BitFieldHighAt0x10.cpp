#include <globaldefs.h>

struct S_a0110 {
    char pad[0x10];
    unsigned int lo : 16;
    unsigned int val : 16;
};

// USA: func_020a0110
ARM void AddClamped16BitFieldHighAt0x10_020a0110(struct S_a0110* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
