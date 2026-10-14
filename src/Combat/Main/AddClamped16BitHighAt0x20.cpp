#include <globaldefs.h>

struct S_a05d8 {
    char pad[0x20];
    unsigned int lo : 16;
    unsigned int val : 16;
};

// USA: func_020a05d8
ARM void AddClamped16BitHighAt0x20_020a05d8(struct S_a05d8* p, unsigned int amount) {
    unsigned int v = p->val + amount;
    if (v > 0xffff) {
        v = 0xffff;
    }
    p->val = v;
}
