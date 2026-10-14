#include <globaldefs.h>

// USA: func_020858f8
ARM float GetScaledBits24To29At0x2fc_020858f8(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 1.0f;
    return (float)((*(int*)(obj + 0x2fc) << 2) >> 26) / 10.0f;
}
