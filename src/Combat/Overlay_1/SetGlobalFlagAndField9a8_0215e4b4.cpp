#include <globaldefs.h>

int GetGlobalField0x1c020421a0();
extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_0215e4b4
ARM int SetGlobalFlagAndField9a8_0215e4b4(void* obj) {
#if defined(jpn)
    enum { flagOffset = 0x789, valueOffset = 0x878 };
#else
    enum { flagOffset = 0x95b, valueOffset = 0x9a8 };
#endif
    char* p = (char*)GetGlobalField0x1c020421a0();
    if (p == NULL) return 0;
    int v = func_ov017_021d60f4(obj);
    p += 0x1000;
    *(unsigned char*)(p + flagOffset) |= 0x4;
    *(int*)(p - 0x1000 + valueOffset) = v;
    return 1;
}
