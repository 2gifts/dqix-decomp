#include <globaldefs.h>

// USA: func_02053ed0
ARM int GetField0x158(void* obj) {
#if defined(jpn)
    return *(int*)((char*)obj + 0x14c);
#else
    return *(int*)((char*)obj + 0x158);
#endif
}
