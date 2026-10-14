#include <globaldefs.h>

struct S_a07b0 {
    char pad[0x38];
    unsigned int val : 24;
    unsigned int top : 8;
};

// USA: func_020a07b0
ARM void AddClamped24BitFieldAt0x38_020a07b0(struct S_a07b0* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffffff) {
        v = 0xffffff;
    }
    p->val = v;
}
