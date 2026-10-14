#include <globaldefs.h>

struct ResetBytesAndSetByte0x16Data {
    unsigned char pad[0x13];
    unsigned char f13;
    unsigned char f14;
    unsigned char f15;
    unsigned char f16;
};

// USA: func_0205c77c
ARM void ResetBytesAndSetByte0x16_0205c77c(struct ResetBytesAndSetByte0x16Data* p, int val) {
    p->f13 = 0;
    p->f15 = 0;
    p->f16 = val;
}
