#include <globaldefs.h>

// USA: func_02085968
ARM float GetPackedRateModifierField1_02085968(char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 1.0f;
    return (float)((*(int*)(obj + 0x300) << 20) >> 26) / 10.0f;
}
