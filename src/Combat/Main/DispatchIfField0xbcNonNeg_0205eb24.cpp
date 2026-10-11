#include <globaldefs.h>

#if defined(jpn)
#endif
extern "C" void func_0203ac40(void*, int, int, int);

// USA: func_0205eb24
ARM void DispatchIfField0xbcNonNeg_0205eb24(void* obj, int a, int b) {
    short s = *(short*)((char*)obj + 0xbc);
    if (s >= 0) {
        func_0203ac40(obj, s, a, b);
    }
}
