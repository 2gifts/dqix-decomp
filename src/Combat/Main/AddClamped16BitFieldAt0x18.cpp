#include <globaldefs.h>

struct S_a01ec {
    char pad[0x18];
    unsigned int val : 16;
    unsigned int hi : 16;
};

// USA: func_020a01ec
ARM void AddClamped16BitFieldAt0x18_020a01ec(struct S_a01ec* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
