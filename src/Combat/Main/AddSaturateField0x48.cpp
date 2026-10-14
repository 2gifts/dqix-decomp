#include <globaldefs.h>

struct S_a0858 {
    char pad[0x48];
    unsigned int value;
};

// USA: func_020a0858
ARM void AddSaturateField0x48_020a0858(struct S_a0858* p, unsigned int amount) {
    unsigned int old = p->value;
    unsigned int sum = amount + old;
    if (sum < old) {
        sum = 0xffffffff;
    }
    p->value = sum;
}
