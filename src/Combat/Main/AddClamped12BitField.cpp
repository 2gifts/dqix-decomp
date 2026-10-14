#include <globaldefs.h>

struct S_a0674 {
    char pad[0x28];
    unsigned int val : 12;
    unsigned int hi : 20;
};

// USA: func_020a0674
ARM void AddClamped12BitField_020a0674(struct S_a0674* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xfff) {
        v = 0xfff;
    }
    p->val = v;
}
