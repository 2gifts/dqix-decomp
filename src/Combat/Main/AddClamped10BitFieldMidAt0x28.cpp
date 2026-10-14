#include <globaldefs.h>

struct S_a06b0 {
    char pad[0x28];
    unsigned int lo : 12;
    unsigned int val : 10;
    unsigned int hi : 10;
};

// USA: func_020a06b0
ARM void AddClamped10BitFieldMidAt0x28_020a06b0(struct S_a06b0* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x3ff) {
        v = 0x3ff;
    }
    p->val = v;
}
