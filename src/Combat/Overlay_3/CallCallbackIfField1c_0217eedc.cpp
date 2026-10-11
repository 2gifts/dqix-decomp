#include <globaldefs.h>

#if defined(jpn)
#define func_ov009_02184c30 func_ov009_02185f5c
#endif
extern "C" void func_ov009_02184c30(void* obj);

// USA: func_ov003_0217eedc
ARM void CallCallbackIfField1c_0217eedc(int* obj) {
    if (obj[7] != 0) {
        func_ov009_02184c30((void*)obj[7]);
    }
}
