#include <globaldefs.h>

// USA: func_0206eaec
ARM int GetBitmapPixel_0206eaec(unsigned char *base, int row, int col) {
    unsigned char *p = base + row * 0x20;
    p += (col << 13) >> 16;
    unsigned short bit = (col & 7) ^ 7;
    return ((p[0x41b] >> bit) & 1) != 0;
}
