#include <globaldefs.h>

// USA: func_020ddb20
ARM int IsField8Bit19Set_020ddb20(unsigned int* obj) {
    return ((obj[2] << 12) >> 31) != 0;
}
