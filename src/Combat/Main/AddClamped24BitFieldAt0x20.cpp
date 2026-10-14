#include <globaldefs.h>

struct S_a02d0 {
    char pad[0x20];
    unsigned int val : 24;
    unsigned int top : 8;
};

// USA: func_020a02d0
ARM void AddClamped24BitFieldAt0x20_020a02d0(struct S_a02d0* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffffff) {
        v = 0xffffff;
    }
    p->val = v;
}
