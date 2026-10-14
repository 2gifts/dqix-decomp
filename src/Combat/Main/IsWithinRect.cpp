#include <globaldefs.h>

// USA: func_02012734
ARM int IsWithinRect_02012734(unsigned char* obj, int x, int y, int width, int height) {
    unsigned short a = *(unsigned short*)(obj + 0x20);
    unsigned short b = *(unsigned short*)(obj + 0x22);
    if (a < x) return 0;
    if (a > x + width) return 0;
    if (b < y) return 0;
    if (b <= y + height) return 1;
    return 0;
}
