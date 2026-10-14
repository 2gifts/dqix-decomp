#include <globaldefs.h>

struct S_a0780 {
    char pad[0x34];
    unsigned int value : 24;
    unsigned int upper : 8;
};

// USA: func_020a0780
ARM void AddClamped24BitFieldAt0x34_020a0780(struct S_a0780* obj, unsigned int amount) {
    unsigned int v = obj->value + amount;
    if (v > 0xffffff) {
        v = 0xffffff;
    }
    obj->value = v;
}
