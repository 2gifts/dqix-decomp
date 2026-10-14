#include <globaldefs.h>

// USA: func_02085888
ARM float GetScaledBits12To17At0x2fc_02085888(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 1.0f;
    return (float)((*(int*)(obj + 0x2fc) << 14) >> 26) / 10.0f;
}
