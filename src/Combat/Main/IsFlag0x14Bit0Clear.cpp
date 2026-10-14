#include <globaldefs.h>

// USA: func_02089060
ARM int IsFlag0x14Bit0Clear_02089060(unsigned char* obj) {
    return (((int*)obj)[5] & 1) == 0;
}
