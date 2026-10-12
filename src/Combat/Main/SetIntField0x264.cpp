#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x258 };
#else
enum { FIELD_OFFSET = 0x264 };
#endif

#if defined(jpn)
#define SetIntField0x264 func_020391b0
extern "C" ARM void func_020391b0(void* obj, int val);
#endif

// USA: func_02039758
ARM void SetIntField0x264(void* obj, int val) {
    *(int*)((char*)obj + FIELD_OFFSET) = val;
}
