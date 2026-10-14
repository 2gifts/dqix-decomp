#include <globaldefs.h>

struct S_a01b8 {
    char pad[0x14];
    unsigned int lo : 20;
    unsigned int val : 12;
};

// USA: func_020a01b8
ARM void AddClamped12BitFieldTopAt0x14_020a01b8(struct S_a01b8* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xfff) {
        v = 0xfff;
    }
    p->val = v;
}
