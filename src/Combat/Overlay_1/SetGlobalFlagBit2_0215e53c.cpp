#include <globaldefs.h>

int GetGlobalField0x1c020421a0();

// USA: func_ov001_0215e53c
ARM int SetGlobalFlagBit2_0215e53c(void) {
#if defined(jpn)
    enum { fieldOffset = 0x789 };
#else
    enum { fieldOffset = 0x95b };
#endif
    int r = GetGlobalField0x1c020421a0();
    if (r == 0) return 0;
    *(unsigned char*)(r + 0x1000 + fieldOffset) |= 2;
    return 1;
}
