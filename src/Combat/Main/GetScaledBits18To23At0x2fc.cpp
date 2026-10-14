#include <globaldefs.h>

// USA: func_020858c0
ARM float GetScaledBits18To23At0x2fc_020858c0(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 1.0f;
    return (float)((*(int*)(obj + 0x2fc) << 8) >> 26) / 10.0f;
}
