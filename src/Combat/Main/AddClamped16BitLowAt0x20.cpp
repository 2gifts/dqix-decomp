#include <globaldefs.h>

struct S_a059c {
    char pad[0x20];
    unsigned int val : 16;
    unsigned int hi : 16;
};

// USA: func_020a059c
ARM void AddClamped16BitLowAt0x20_020a059c(struct S_a059c* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
