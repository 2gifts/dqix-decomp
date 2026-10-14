#include <globaldefs.h>

// USA: func_02083bc0
ARM int GetBitInArray0x910_02083bc0(unsigned char* obj, int index) {
    unsigned char* p = obj + 0x910;
    return p[index / 8] & (1 << (index % 8));
}
