#include <globaldefs.h>

int GetGlobalField0x1c020421a0();

// USA: func_ov001_0215e4f0  (semantic: ClearGlobalByte9b1_0215e4f0)
extern "C" ARM int func_ov001_0215e4f0(void) {
#if defined(jpn)
    enum { fieldOffset = 0x7e1 };
#else
    enum { fieldOffset = 0x9b1 };
#endif
    int r = GetGlobalField0x1c020421a0();
    if (r == 0) return 0;
    *(unsigned char*)(r + 0x1000 + fieldOffset) = 0;
    return 1;
}
