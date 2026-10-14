#include <globaldefs.h>

extern "C" unsigned char* func_0205ec34(void);

// USA: func_020107a8
ARM void SetField5cb4AndRecordByte1_020107a8(char* obj, int v) {
#if defined(jpn)
    *(int*)(obj + 0x5a54) = v;
#else
    *(int*)(obj + 0x5cb4) = v;
#endif
    unsigned char* p = func_0205ec34();
    unsigned char* rec = p + p[0x332] * 0x1c;
    rec[1] = v;
}
