#include <globaldefs.h>

// USA: func_0205e7dc
ARM void SetBitInArray0x1524_0205e7dc(unsigned char* obj, int index) {
    unsigned char* p = obj + 0x1524;
    p[(unsigned)index >> 3] |= 1 << (index % 8);
}
