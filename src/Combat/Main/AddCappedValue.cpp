#include <globaldefs.h>

struct Field0x30 {
    char pad[0x30];
    unsigned int value : 24;
    unsigned int upper : 8;
};

// USA: func_020a0750
ARM void AddCappedValue_020a0750(struct Field0x30* obj, unsigned int amount) {
    unsigned int v = obj->value + amount;
    if (v > 0xffffff) {
        v = 0xffffff;
    }
    obj->value = v;
}
