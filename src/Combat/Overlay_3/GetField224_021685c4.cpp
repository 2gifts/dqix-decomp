#include <globaldefs.h>

// USA: func_ov003_021685c4
ARM int GetField224_021685c4(void* obj) {
#if defined(jpn)
    return *(int*)((char*)obj + 0xdc);
#else
    return *(int*)((char*)obj + 0xe0);
#endif
}
