#include <globaldefs.h>

struct S_a06ec {
    char pad[0x28];
    unsigned int lo : 22;
    unsigned int val : 10;
};

// USA: func_020a06ec
ARM void AddClamped10BitFieldHighAt0x28_020a06ec(struct S_a06ec* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x3ff) {
        v = 0x3ff;
    }
    p->val = v;
}
