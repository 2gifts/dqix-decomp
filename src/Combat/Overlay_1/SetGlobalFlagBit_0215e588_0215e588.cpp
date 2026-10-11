#include <globaldefs.h>

int GetGlobalField0x1c020421a0();

// USA: func_ov001_0215e588
ARM int SetGlobalFlagBit_0215e588_0215e588(void) {
#if defined(jpn)
    enum { fieldOffset = 0x789 };
#else
    enum { fieldOffset = 0x95b };
#endif
    int r = GetGlobalField0x1c020421a0();
    if (r == 0) return 0;
    *(unsigned char*)(r + 0x1000 + fieldOffset) |= 0x80;
    return 1;
}
