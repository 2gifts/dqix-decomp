#include <globaldefs.h>

#if defined(jpn)
enum { FIELD_OFFSET = 0x258 };
#else
enum { FIELD_OFFSET = 0x264 };
#endif

// USA: func_02039758
ARM void SetIntField0x264_02039758(void* obj, int val) {
    *(int*)((char*)obj + FIELD_OFFSET) = val;
}
