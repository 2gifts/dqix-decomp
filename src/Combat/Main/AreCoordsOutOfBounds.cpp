#include <globaldefs.h>

void SelectCoordsByFlag0x24_02012a84(unsigned char* obj, int* out1, int* out2);

// USA: func_02012b54
ARM int AreCoordsOutOfBounds_02012b54(unsigned char* obj) {
    int a, b;
    SelectCoordsByFlag0x24_02012a84(obj, &a, &b);
    if (a < 2) return 1;
    if (a > 0xfd) return 1;
    if (b < 2) return 1;
    if (b > 0xbd) return 1;
    return 0;
}
