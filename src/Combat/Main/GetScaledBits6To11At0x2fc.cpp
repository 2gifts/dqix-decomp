#include <globaldefs.h>

// USA: func_02085850
ARM float GetScaledBits6To11At0x2fc_02085850(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 1.0f;
    return (float)((*(int*)(obj + 0x2fc) << 20) >> 26) / 10.0f;
}
