#include <globaldefs.h>

// USA: func_02012a84
ARM void SelectCoordsByFlag0x24_02012a84(unsigned char* obj, int* out1, int* out2) {
    if (*(unsigned short*)(obj + 0x24) != 0) {
        *out1 = *(unsigned short*)(obj + 0x20);
        *out2 = *(unsigned short*)(obj + 0x22);
    } else {
        *out1 = *(int*)(obj + 0x38);
        *out2 = *(int*)(obj + 0x3c);
    }
}
