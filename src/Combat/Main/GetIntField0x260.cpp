#include <globaldefs.h>

// USA: func_02039750
ARM int GetIntField0x260_02039750(void* obj) {
#if defined(jpn)
    return *(int*)((char*)obj + 0x254);
#else
    return *(int*)((char*)obj + 0x260);
#endif
}
