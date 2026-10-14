#include <globaldefs.h>

struct S_a0810 {
    char pad[0x40];
    unsigned int val : 24;
    unsigned int top : 8;
};

// USA: func_020a0810
ARM void AddClamped24BitFieldAt0x40_020a0810(struct S_a0810* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffffff) {
        v = 0xffffff;
    }
    p->val = v;
}
