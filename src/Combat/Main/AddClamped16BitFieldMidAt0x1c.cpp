#include <globaldefs.h>

struct S_a0294 {
    char pad[0x1c];
    unsigned int lo : 10;
    unsigned int val : 16;
    unsigned int hi : 6;
};

// USA: func_020a0294
ARM void AddClamped16BitFieldMidAt0x1c_020a0294(struct S_a0294* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
