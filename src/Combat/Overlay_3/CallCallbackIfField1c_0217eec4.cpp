#include <globaldefs.h>
#if defined(jpn)
#define func_ov009_02184bbc func_ov009_02185ee8
#endif

#if defined(jpn)
#endif
extern "C" void func_ov009_02184bbc(void* obj);

// USA: func_ov003_0217eec4
ARM void CallCallbackIfField1c_0217eec4(int* obj) {
    if (obj[7] != 0) {
        func_ov009_02184bbc((void*)obj[7]);
    }
}
