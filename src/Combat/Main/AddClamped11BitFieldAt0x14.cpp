#include <globaldefs.h>

struct S_a04c8 {
    char pad[0x14];
    unsigned int lo : 18;
    unsigned int val : 11;
    unsigned int hi : 3;
};

// USA: func_020a04c8
ARM void AddClamped11BitFieldAt0x14_020a04c8(struct S_a04c8* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x5dc) {
        v = 0x5dc;
    }
    p->val = v;
}
