#include <globaldefs.h>

// USA: func_020859a0
ARM float GetPackedRateModifierField2_020859a0(char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 1.0f;
    return (float)((*(int*)(obj + 0x300) << 14) >> 26) / 10.0f;
}
