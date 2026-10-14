#include <globaldefs.h>

extern "C" unsigned char* func_0205ec34(void);

// USA: func_02010774
ARM void SetField5cb0AndRecordByte0_02010774(char* obj, int v) {
#if defined(jpn)
    *(int*)(obj + 0x5a50) = v;
#else
    *(int*)(obj + 0x5cb0) = v;
#endif
    unsigned char* p = func_0205ec34();
    p[p[0x332] * 0x1c] = v;
}
