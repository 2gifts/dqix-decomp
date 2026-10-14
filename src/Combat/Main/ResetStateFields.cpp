#include <globaldefs.h>

struct Bits14_89074 {
    unsigned int pad20 : 20;
    unsigned int f20 : 1;
    unsigned int f21 : 1;
    unsigned int pad_rest : 10;
};

// USA: func_02089074
ARM void ResetStateFields_02089074(unsigned char* obj) {
    struct Bits14_89074* b;
    obj[0x7a] = 3;
    obj[0x9d] = 0;
    *(int*)(obj + 0x18) |= 0x40;
    b = (struct Bits14_89074*)(obj + 0x14);
    b->f20 = 0;
    b->f21 = 0;
}
