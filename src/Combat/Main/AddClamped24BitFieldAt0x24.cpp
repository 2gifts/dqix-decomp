#include <globaldefs.h>

struct S_a0300 {
    char pad[0x24];
    unsigned int val : 24;
    unsigned int top : 8;
};

// USA: func_020a0300
ARM void AddClamped24BitFieldAt0x24_020a0300(struct S_a0300* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffffff) {
        v = 0xffffff;
    }
    p->val = v;
}
