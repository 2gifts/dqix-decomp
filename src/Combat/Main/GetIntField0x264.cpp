#include <globaldefs.h>

// USA: func_02039760
ARM int GetIntField0x264_02039760(void* obj) {
#if defined(jpn)
    return *(int*)((char*)obj + 0x258);
#else
    return *(int*)((char*)obj + 0x264);
#endif
}
