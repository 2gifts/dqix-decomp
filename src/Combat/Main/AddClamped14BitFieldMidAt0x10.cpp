#include <globaldefs.h>

struct S_a03f8 {
    char pad[0x10];
    unsigned int lo : 9;
    unsigned int val : 14;
    unsigned int hi : 9;
};

// USA: func_020a03f8
ARM void AddClamped14BitFieldMidAt0x10_020a03f8(struct S_a03f8* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0x270f) {
        v = 0x270f;
    }
    p->val = v;
}
