#include <globaldefs.h>

extern "C" void func_ov003_0215caa4(void* p);

// USA: func_ov003_0216d7ec
ARM void SetFlag2AndMaybeCall_0216d7ec(char* obj) {
#if defined(jpn)
    enum { flagOffset = 0x127c };
#else
    enum { flagOffset = 0x13ec };
#endif
    *(unsigned char*)(obj + flagOffset) |= 2;
    short val = *(short*)(obj + 0x4);
    if (val == 3) {
        func_ov003_0215caa4(obj + 0x14);
    }
}
