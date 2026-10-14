#include <globaldefs.h>

struct S_a0608 {
    char pad[0x24];
    unsigned int val : 16;
    unsigned int hi : 16;
};

// USA: func_020a0608
ARM void AddClamped16BitLowAt0x24_020a0608(struct S_a0608* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
