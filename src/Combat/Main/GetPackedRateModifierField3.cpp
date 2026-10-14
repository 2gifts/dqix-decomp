#include <globaldefs.h>

// USA: func_020859d8
ARM float GetPackedRateModifierField3_020859d8(char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 1.0f;
    return (float)((*(int*)(obj + 0x300) << 8) >> 26) / 10.0f;
}
