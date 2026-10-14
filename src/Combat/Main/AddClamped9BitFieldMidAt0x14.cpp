#include <globaldefs.h>

struct S_a0494 {
    char pad[0x14];
    unsigned int lo : 9;
    unsigned int val : 9;
    unsigned int hi : 14;
};

// USA: func_020a0494
ARM void AddClamped9BitFieldMidAt0x14_020a0494(struct S_a0494* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x1f4) {
        v = 0x1f4;
    }
    p->val = v;
}
