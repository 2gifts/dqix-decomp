#include <globaldefs.h>

struct State020d1344 {
    unsigned char pad[5];
    unsigned char bit0 : 1;
};

// USA: func_020d1344
ARM int GetState0x27ffc30Bit0_020d1344() {
    volatile struct State020d1344* p = (struct State020d1344*)0x27ffc30;
    return p->bit0;
}
