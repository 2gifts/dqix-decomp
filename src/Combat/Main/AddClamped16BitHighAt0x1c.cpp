#include <globaldefs.h>

struct S_a056c {
    char pad[0x1c];
    unsigned int lo : 16;
    unsigned int val : 16;
};

// USA: func_020a056c
ARM void AddClamped16BitHighAt0x1c_020a056c(struct S_a056c* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
