#include <globaldefs.h>

struct S_a0434 {
    char pad[0x10];
    unsigned int lo : 23;
    unsigned int val : 9;
};

// USA: func_020a0434
ARM void AddClamped9BitFieldTopAt0x10_020a0434(struct S_a0434* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x1f4) {
        v = 0x1f4;
    }
    p->val = v;
}
