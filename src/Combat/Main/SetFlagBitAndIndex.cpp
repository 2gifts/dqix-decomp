#include <globaldefs.h>

struct SetFlagBitStruct {
    char pad[0x50];
    unsigned int f50;
    unsigned short f54;
};

// USA: func_02086598
ARM void SetFlagBitAndIndex_02086598(struct SetFlagBitStruct* s, int n) {
    s->f54 |= 1 << n;
    s->f50 = n;
}
