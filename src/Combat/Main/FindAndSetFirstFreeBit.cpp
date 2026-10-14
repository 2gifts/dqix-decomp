#include <globaldefs.h>

// USA: func_02042a90
ARM int FindAndSetFirstFreeBit_02042a90(int unused, unsigned char* p, unsigned int count) {
    unsigned int i;
    for (i = 0; i < count; i++) {
        unsigned char byte = *p;
        int j;
        for (j = 0; j < 8; j++) {
            unsigned char mask = 1 << j;
            if ((byte & mask) == 0) {
                *p |= mask;
                return i * 8 + j;
            }
        }
        p++;
    }
    return -1;
}
