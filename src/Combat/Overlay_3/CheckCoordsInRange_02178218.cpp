#include <globaldefs.h>

extern unsigned char data_02114e54;

void SelectCoordsByFlag0x24_02012a84(unsigned char* obj, int* out1, int* out2);

// USA: func_ov003_02178218  (semantic: CheckCoordsInRange_02178218)
extern "C" ARM int func_ov003_02178218(void) {
    unsigned char* d = &data_02114e54;
    if (*(unsigned char*)(d + 0x5f) == 0 || *(unsigned short*)(d + 0x24) == 0) {
        return 0;
    }
    int x, y;
    SelectCoordsByFlag0x24_02012a84(d, &x, &y);
    if (x < 0x94 || x > 0xa7) {
        return 0;
    }
    if (y >= 0x24 && y <= 0x2d) return 1;
    if (y >= 0x30 && y <= 0x39) return -1;
    return 0;
}
