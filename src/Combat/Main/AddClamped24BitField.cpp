#include <globaldefs.h>

struct S_a0720 {
    char pad[0x2c];
    unsigned int val : 24;
    unsigned int top : 8;
};

// USA: func_020a0720
ARM void AddClamped24BitField_020a0720(struct S_a0720* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffffff) {
        v = 0xffffff;
    }
    p->val = v;
}
