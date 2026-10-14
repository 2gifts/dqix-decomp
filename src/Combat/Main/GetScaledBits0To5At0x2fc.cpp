#include <globaldefs.h>

// USA: func_02085818
ARM float GetScaledBits0To5At0x2fc_02085818(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 1.0f;
    return (float)((*(int*)(obj + 0x2fc) << 26) >> 26) / 10.0f;
}
