#include <globaldefs.h>

struct S_a0840 {
    char pad[0x44];
    unsigned int value;
};

// USA: func_020a0840
ARM void AddSaturateField0x44_020a0840(struct S_a0840* p, unsigned int amount) {
    unsigned int old = p->value;
    unsigned int sum = amount + old;
    if (sum < old) {
        sum = 0xffffffff;
    }
    p->value = sum;
}
