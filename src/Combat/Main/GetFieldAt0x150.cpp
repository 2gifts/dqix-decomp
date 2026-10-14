#include <globaldefs.h>

// USA: func_02053c6c
ARM int GetFieldAt0x150_02053c6c(unsigned char* obj) {
#if defined(jpn)
    return *(int*)(obj + 0x144);
#else
    return *(int*)(obj + 0x150);
#endif
}
