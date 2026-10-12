#include <globaldefs.h>

#if defined(jpn)
#define ClearField0x84Callback func_020bf3c8
extern "C" ARM void func_020bf3c8(void*, void*, void* obj);
#endif

// USA: func_020bd8fc
ARM void ClearField0x84Callback(void*, void*, void* obj) {
    *(int*)((char*)obj + 0x84) = 0;
}
