#include <globaldefs.h>

// USA: func_020a27b8
ARM void ClearIntAt0x23c_020a27b8(unsigned char* obj) {
    *(unsigned int*)(obj + 0x23c) = 0;
}
