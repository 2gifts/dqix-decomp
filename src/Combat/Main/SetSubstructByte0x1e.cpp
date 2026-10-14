#include <globaldefs.h>

// USA: func_020493dc
ARM void SetSubstructByte0x1e_020493dc(unsigned char* obj, unsigned char value) {
    unsigned char* p = *(unsigned char**)(obj + 0x13c);
    if (p != 0) {
        p[0x1e] = value;
    }
}
