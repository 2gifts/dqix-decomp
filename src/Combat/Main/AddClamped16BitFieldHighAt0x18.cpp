#include <globaldefs.h>

struct S_a0228 {
    char pad[0x18];
    unsigned int lo : 16;
    unsigned int val : 16;
};

// USA: func_020a0228
ARM void AddClamped16BitFieldHighAt0x18_020a0228(struct S_a0228* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
