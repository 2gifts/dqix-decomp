#include <globaldefs.h>

extern "C" unsigned char* func_0205ec34(void);

// USA: func_020107dc
ARM void SetSlotByte020107dc(char* base, int val) {
    unsigned char* p;
#if defined(jpn)
    *(int*)(base + 0x5a58) = val;
#else
    *(int*)(base + 0x5cb8) = val;
#endif
    p = func_0205ec34();
    p += p[0x332] * 0x1c;
    p[2] = (unsigned char)val;
}
